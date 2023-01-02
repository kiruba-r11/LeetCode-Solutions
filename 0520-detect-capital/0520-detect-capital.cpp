class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        int cap = 0;
        for(int i = 0; i < n; i++) {
            if(word[i] >= 65 && word[i] <= 90) cap++;
        }
        
        if(cap == 0 || cap == n) return true;
        if(cap == 1) return word[0] >= 65 && word[0] <= 90;
        return false;
    }
};