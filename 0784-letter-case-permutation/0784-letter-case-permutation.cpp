class Solution {
public:
    void letterCase(string &s , int i , string &cur , vector <string> &ans) {
        
        if(s.size() == i) {
            ans.push_back(cur);
            return;
        }
        
        if(isdigit(s[i])) {
            cur += s[i];
            letterCase(s , i + 1 , cur , ans);
            cur.pop_back();
        } else {
            
            cur += tolower(s[i]);
            letterCase(s , i + 1 , cur , ans);
            cur.pop_back();
            
            cur += toupper(s[i]);
            letterCase(s , i + 1 , cur , ans);
            cur.pop_back();
        }

    }
    
    vector<string> letterCasePermutation(string s) {
        vector <string> ans;
        string cur = "";
        
        letterCase(s , 0 , cur , ans);
        return ans;
    }
};