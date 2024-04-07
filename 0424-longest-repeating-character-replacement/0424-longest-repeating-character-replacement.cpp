class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0 , j = 0;
        int n = s.size();
        int maxfreq = 0;
        int ans = 0;
        
        map <int , int> hash;
        
        while(j < n) {
            hash[s[j] - 'A']++;
            maxfreq = max(maxfreq , hash[s[j] - 'A']);
            int extra = j - i + 1 - maxfreq;
            while(extra > k) {
                hash[s[i] - 'A']--;
                if(hash[s[i] - 'A'] == maxfreq) {
                    maxfreq--;
                } else {    
                    extra--;
                }
                i++;
            }
            
            if(extra <= k) ans = max(ans , j - i + 1);
            j++;
        }
        
        return ans;
    }
};