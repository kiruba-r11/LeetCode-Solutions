class Solution {
public:
    string multiply_string(string &cur , int times) {
    
        string ans = "";
        for(int i = 0; i < times; i++) {
            ans += cur;
        }
        
        return ans;
    }
    
    string decode(string &s , int start , int end) {
        string ans = "";
        
        int newStart = -1;
        int newEnd = -1;
        
        int open = 0;
        int num = 0;
        
        for(int i = start; i <= end; i++) {
            if(s[i] >= 48 && s[i] <= 57) {
                if(open == 0)
                    num = num * 10 + (s[i] - '0');
            } else if(s[i] == '[') {
                if(open == 0)
                    newStart = i;
                open++;
            } else if(s[i] == ']') {
                open--;
                if(open == 0) {
                    newEnd = i;

                    string cur_ans = decode(s , newStart + 1 , newEnd - 1);
                    ans += multiply_string(cur_ans , num);

                    newStart = -1;
                    newEnd = -1;
                    num = 0;
                }
            } else {
                if(open == 0) 
                    ans += s[i];
            }
        }
        
        return ans;
    }
    string decodeString(string s) {
        int n = s.size();
        return decode(s , 0 , n - 1);
    }
};