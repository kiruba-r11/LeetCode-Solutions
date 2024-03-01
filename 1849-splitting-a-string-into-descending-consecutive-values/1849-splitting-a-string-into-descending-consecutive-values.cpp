class Solution {
public:
    bool valid(string &cur , string &prev) {
        if(prev == "-") return true;
        int clen = cur.size();
        int plen = prev.size();
        
        int clzero = 0;
        int plzero = 0;
        
        for(int i = 0; i < clen; i++) {
            if(cur[i] == '0') clzero++;
            else break;
        }
        
        for(int i = 0; i < plen; i++) {
            if(prev[i] == '0') plzero++;
            else break;
        }
        
        if(abs((clen - clzero) - (plen - plzero)) >= 2) return false;
            
        long long c = stoll(cur);
        long long p = stoll(prev);
        
        if(c < p && (p - c) == 1) return true;
        return false;
    }
    
    bool solve(string &s , string &prev , int start) {
        if(start == s.size()) {
            if(prev == s) return false;
            return true;
        }
        
        string prefix = "";
        for(int i = start; i < s.size(); i++) {
            prefix += s[i];
            if(valid(prefix , prev)) {
                string temp = prev;
                prev = prefix;
                if(solve(s , prev , i + 1)) return true;
                prev = temp;
            }
        }
        
        return false;
    }
    
    bool splitString(string s) {
        string prev = "-";
        return solve(s , prev , 0);
    }
};