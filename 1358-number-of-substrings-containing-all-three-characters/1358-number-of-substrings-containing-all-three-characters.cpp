class Solution {
public:
    bool valid(unordered_map <char , int> &hash) {
        return hash['a'] > 0 && hash['b'] > 0 && hash['c'] > 0;
    }
    int numberOfSubstrings(string s) {
        int n = s.size();
        int i = 0 , j = 0 , ans = 0;
        unordered_map <char , int> hash;
        
        while(j <= n) {
            if(valid(hash)) {
                ans += n - j + 1;   
                hash[s[i]]--;
                i++;
            } else {
                if(j < n) hash[s[j]]++;
                j++;
            }
        }
        
        return ans;
    }
};