class Solution {
public:
    char repeatedCharacter(string s) {
        int mask = 0;
        int n = s.size();
        for(int i = 0; i < n; i++) {    
            int bit = (1 << (s[i] - 'a'));
            if(mask & bit) return s[i];
            mask = mask | bit;
        }
        
        return '-';
    }
};