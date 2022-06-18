class Solution {
public:
    int longestPalindrome(string s) {
        vector <int> hash(128 , 0);
        int n = s.size() , ans = 0;
        bool check = false;
        
        for(int i = 0; i < n; i++) {
            hash[s[i]]++;
        }
        
        for(int i = 0; i < 128; i++) {
            if(hash[i] & 1) check = true;
            ans += hash[i] - (hash[i] & 1);
        }
        
        if(check) ans++;
        return ans;
    }
};