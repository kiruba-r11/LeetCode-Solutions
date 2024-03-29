class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        int n = text.size();
        int first = 0 , second = 0;
        long long ans = 0;
        
        for(int i = 0; i < n; i++) {
            if(text[i] == pattern[0]) first++;
            if(text[i] == pattern[1]) second++;
        }
        
        int tempsecond = second;
        for(int i = 0; i < n; i++) {
            if(text[i] == pattern[0]) {
                ans += tempsecond;
            } else if(text[i] == pattern[1]) {
                tempsecond--;
            }
        }
        
        int choice1 = 0 , choice2 = 0;
        choice1 = second;
        choice2 = first;
        
        ans += max(choice1 , choice2);
        
        if(pattern[0] == pattern[1]) ans /= 2;
        return ans;
    }
};