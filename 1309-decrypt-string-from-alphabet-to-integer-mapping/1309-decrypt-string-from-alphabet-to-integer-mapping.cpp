class Solution {
public:
    char numToChar(char ch) {
    
        return char(int(ch - '0') + 96);
    }
    
    
    string freqAlphabets(string s) {
        
        /*
        
        O(N) time and space (output string) complexity;
        Idea -> Basic String Manipulations
        
        */
        
        int n = s.size();
        string ans = "";
        
        for(int i = 0; i < n; i++) {
            
            if(s[i] == '1' || s[i] == '2') {
                if(i + 2 < n && s[i + 2] == '#') {
                    
                    char ch = char(int(s[i] - '0') * 10 + int(s[i + 1] - '0') + 96);
                    ans += ch;
                    
                    i += 2;
                } else {
                    char ch = numToChar(s[i]);
                    ans += ch;
                }
            } else {
                char ch = numToChar(s[i]);
                ans += ch;
            }
        }
        
        return ans;
    }
};