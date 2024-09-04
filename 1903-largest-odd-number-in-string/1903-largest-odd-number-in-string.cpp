class Solution {
public:
    bool is_odd(char ch) {
        string num = "13579";
        for(auto i: num) {
            if(i == ch) return true;
        }
        return false;
    }
    
    string largestOddNumber(string num) {
        string prefix = "";
        int idx = -1;
        int n = num.size();
        for(int i = 0; i < n; i++) {
            if(is_odd(num[i])) {
                idx = i;
            }
        }
        if(idx == -1) return "";
        for(int i = 0; i <= idx; i++) {
            prefix.push_back(num[i]);
        }
        
        return prefix;
    }
};