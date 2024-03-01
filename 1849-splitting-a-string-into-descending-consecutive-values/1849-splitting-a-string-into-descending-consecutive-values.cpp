class Solution {
public:
    bool valid(long long &cur , long long &prev , int i , int n) {
        cout << cur << " " << prev << endl;
        if(i == n - 1 && prev == -1) return false;
        if(prev == -1) return true;
        
        if(cur < prev && (prev - cur) == 1) return true;
        return false;
    }
    
    bool solve(string &t , string &s , long long &prev , int start) {
        if(start == s.size()) {
            // if(to_string(prev) == t) return false;
            // if(prev == -1) return false;
            return true;
        }
        
        long long prefix = 0;
        int len = s.size() / 2 + 1;
        
        for(int i = start; i < s.size(); i++) {
            prefix = prefix * 10LL + (s[i] - '0');
            if(prefix > pow(10 , len)) break;
            
            if(valid(prefix , prev , i , s.size())) {
                int temp = prev;
                prev = prefix;
                if(solve(t , s , prev , i + 1)) return true;
                prev = temp;
            }
        }
        
        return false;
    }
    
    bool splitString(string s) {
        long long prev = -1;
        string temp = "";
        int idx = -1;
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '0') continue;
            else {
                idx = i;
                break;
            }
        }
        
        for(int i = idx; i < s.size(); i++) {
            temp += s[i];
        }
        cout << temp << endl;
        return solve(temp , s , prev , 0);
    }
};