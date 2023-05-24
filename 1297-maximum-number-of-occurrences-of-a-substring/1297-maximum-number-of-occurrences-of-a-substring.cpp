class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        
        int n = s.size();
        int i = 0 , j = 0 , ans = 0;
        
        unordered_map <int , int> count;
        unordered_map <string , int> occurrence;
        
        while(j < n) {
            int window = j - i + 1;
            if(window <= minSize) {
                count[s[j]]++;
                
                if(window == minSize) {
                    if(count.size() <= maxLetters) {
                        ans = max(ans , ++occurrence[s.substr(i , minSize)]);
                    }
                }
                
                j++;
            } else {
                if(count[s[i]] == 1) count.erase(s[i]);
                else count[s[i]]--;
                
                i++;
            }
        }
        
        return ans;
    }
};