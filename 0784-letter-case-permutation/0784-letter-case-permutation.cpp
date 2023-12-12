class Solution {
public:
    vector <string> ans;
    void solve(string &s , int i) {
        
        if(i == s.size()) {
            ans.push_back(s);
            return;
        }
        
        if(isdigit(s[i])) {
            solve(s , i + 1);
        } else {
            solve(s , i + 1);
            char temp = s[i];
            
            if(islower(temp)) s[i] = toupper(temp);
            else s[i] = tolower(temp);
            
            solve(s , i + 1);
            
            s[i] = temp;
        }
    }
    
    vector<string> letterCasePermutation(string s) {
        solve(s , 0);
        return ans;
    }
};