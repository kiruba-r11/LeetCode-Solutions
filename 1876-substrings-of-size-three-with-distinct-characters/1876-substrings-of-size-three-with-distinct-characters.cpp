class Solution {
public:
    int countGoodSubstrings(string s) {
        // Fixed Window
        int k = 3;
        int n = s.size();
        int i = 0 , j = 0;
        int ans = 0;
        
        unordered_map <char , int> hash;
        
        while(j < n) {
            int window = j - i + 1;
            if(window <= k) {
                hash[s[j]]++;
                if(window == k) {
                    if(hash.size() == k) ans++;
                }
                j++;
            } else {
                if(hash[s[i]] == 1) {
                    hash.erase(s[i]);
                } else {
                    hash[s[i]]--;
                }
                i++;
            }
        }
        
        return ans;
    }
};