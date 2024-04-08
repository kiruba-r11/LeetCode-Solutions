class Solution {
public:
    bool valid(vector <int> &hash) {
        for(int i = 0; i < 26; i++) {
            if(hash[i] > 2) return false;
        }
        return true;
    }
    
    int maximumLengthSubstring(string s) {
        int i = 0 , j = 0;
        int n = s.size();
        int ans = 0;
        
        vector <int> hash(26);
        
        while(j < n) {
            hash[s[j] - 'a']++;
            while(valid(hash) == false) {
                hash[s[i] - 'a']--;
                i++;
            }
            if(valid(hash)) ans = max(ans , j - i + 1);
            j++;
        }
        
        return ans;
    }
};