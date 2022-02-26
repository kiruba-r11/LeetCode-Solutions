class Solution {
public:
    void helper(string &s , string &ts) {
        
        int n = s.size();
        int i = n - 1 , hcnt = 0;
        
        while(i >= 0) {
            int ti = i;
            while(ti >= 0 && s[ti] == '#') ti--;
            
            hcnt += i - ti;
            
            while(ti >= 0 && s[ti] != '#') {
                if(hcnt == 0) {
                    ts = s[ti] + ts;
                } else hcnt--;
                ti--;
            }
            i = ti;
        }
        
    }
    bool backspaceCompare(string s, string t) {
        
        /*
        
        O(N) time and O(s) (s -> no. of characters in resultant string) space complexity
        Idea -> String Manipulations
        
            1. Just remove the character when a hash appears.
            2. Above approach can be done using Stack or String Manipulations
        
        */
        
        string ts = "" , tt = "";
        
        helper(s , ts);
        helper(t , tt);
        
        return ts == tt;
    }
};