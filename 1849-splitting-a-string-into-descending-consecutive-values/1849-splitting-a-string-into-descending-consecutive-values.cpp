class Solution {
public:
    bool valid(long long &cur , long long &prev , int i , int n) {
        if(i == n - 1 && prev == -1) return false;
        if(prev == -1) return true;
        
        if(cur < prev && (prev - cur) == 1) return true;
        return false;
    }
    
    bool solve(string &s , long long &prev , int start) {
        if(start == s.size()) return true;
        
        long long prefix = 0;
        int len = s.size() / 2 + 1;
        
        for(int i = start; i < s.size(); i++) {
            prefix = prefix * 10LL + (s[i] - '0');
            if(prefix > pow(10 , len)) break;
            
            if(valid(prefix , prev , i , s.size())) {
                int temp = prev;
                prev = prefix;
                if(solve(s , prev , i + 1)) return true;
                prev = temp;
            }
        }
        
        return false;
    }
    
    bool splitString(string s) {
        long long prev = -1;
        return solve(s , prev , 0);
    }
};