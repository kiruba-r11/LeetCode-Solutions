class Solution {
public:
    bool condition(map <char , int> &hash , int k) {
        for(auto i: hash) {
            int cnt = i.second;
            if(i.second < k) return false;
        }
        return true;
    }
    
    int takeCharacters(string s, int k) {
        int i = 0 , j = 0;
        int ans = -1;
        int n = s.size();
        map <char , int> hash;
        
        for(int i = 0; i < n; i++) hash[s[i]]++;
        
        string ss = "abc";
        int cnt = 0;
        for(int i = 0; i < 3; i++) {
            if(hash[ss[i]] < k) return -1;
            if(hash[ss[i]] == k) cnt++;
        }
        
        if(cnt == 3) return n;
        
        while(j < n) {
            hash[s[j]]--;
            while(i < j && condition(hash , k) == false) {
                hash[s[i]]++;
                i++;
            }
            if(condition(hash , k) == true) ans = max(ans , j - i + 1);
            j++;
        }
        
        return ans == -1 ? -1 : n - ans;
    }
};