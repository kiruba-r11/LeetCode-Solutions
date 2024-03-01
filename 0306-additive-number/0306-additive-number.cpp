class Solution {
public:
    bool invalid(string &s) {
        if(s.size() != 1 && s[0] == '0') return true;
        return false;
    }
    
    bool valid(string &first , string &second , string &third) {

        if(invalid(first) || invalid(second) || invalid(third)) return false;
        
        int flen = first.size();
        int slen = second.size();
        int tlen = third.size();
        
        int diff = tlen - (flen + slen);
        if(diff >= 2) return false;
        
        long long f = stoll(first);
        long long s = stoll(second);
        long long t = stoll(third);
        
        return t == f + s;
        
    }
    
    bool solve(string &s , int start , string first , string second , bool third) {
        
        if(start == s.size()) {
            if(first == "" || second == "" || !third) return false;
            return true;
        }
        
        string prefix = "";
        for(int i = start; i < s.size(); i++) {
            prefix += s[i];
            if(first == "") {
                if(solve(s , i + 1 , prefix , second , false)) return true;
            } else if(second == "") {
                if(solve(s , i + 1 , first , prefix , false)) return true;
            } else {
                if(valid(first , second , prefix)) {
                    if(solve(s , i + 1 , second , prefix , true)) return true;
                }
            }
        }
        
        return false;
    }
    
    bool isAdditiveNumber(string num) {
        return solve(num , 0 , "" , "" , false);
    }
};