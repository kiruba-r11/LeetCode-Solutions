class Solution {
public:
    char change(char ch , int val) {
        
        ch = char(((ch - 97) + val) % 26 + 97);
        return ch;
    }
    
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size();
        int prefix = 0;
        for(int i = n - 1; i >= 0; i--) {
            prefix += shifts[i] % 26;
            prefix %= 26;
            
            s[i] = change(s[i] , prefix);
        }
        
        return s;
    }
};