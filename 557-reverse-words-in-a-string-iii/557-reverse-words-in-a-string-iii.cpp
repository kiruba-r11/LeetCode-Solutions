class Solution {
public:
    string reverseWords(string s) {
        
        /*
        
        O(N) time and space (output) complexity
        
        */
        
        int n = s.size();
        string ans = "" , temp = "";
        
        for(int i = 0; i < n; i++) {
            
            int j = i;
            temp = "";
            while(j < n && s[j] != ' ') {
                temp = s[j] + temp;
                j++;
            }
            
            if(j < n) temp += " ";
            
            ans += temp;
            i = j;
        }
        
        return ans;
    }
};










