class Solution {
public:
    bool isUpper(char &ch) {
        return ch >= 65 && ch <= 90;
    }
    
    void toLower(char &ch) {
        if(ch >= 65 && ch <= 90) ch = char(ch + 32);
    }
    
    string toLowerCase(string s) {
        
        /*
        
        O(N) time and O(1) space complexity
        Idea -> ASCII values
        
        */
        
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(isUpper(s[i])) toLower(s[i]);
        }
        
        return s;
    }
};