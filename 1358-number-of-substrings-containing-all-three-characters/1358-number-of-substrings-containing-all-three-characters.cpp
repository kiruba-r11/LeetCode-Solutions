class Solution {
public:
    int numberOfSubstrings(string s) {
        int i = 0 , j = 0;
        int n = s.size();
        int ans = 0;
        map <int , int> hash;
        
        while(j < n) {
            hash[s[j] - 'a']++;
            while(hash.size() == 3) {
                if(hash[s[i] - 'a'] == 1) {
                    break;
                } else {
                    hash[s[i] - 'a']--;
                    i++;
                }
            }
            if(hash.size() == 3) {
                ans += i + 1;
            }
            j++;
        }
        
        return ans;
    }
};