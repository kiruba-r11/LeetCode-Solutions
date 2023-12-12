class Solution {
public:
    vector <string> ans;
    void solve(int n , string &cur , int open) {
    
        if(open < 0) return;
        if(n == 0) {
            if(open == 0) ans.push_back(cur);
            return;
        }
        
        cur += "(";
        solve(n - 1 , cur , open + 1);
        cur.pop_back();
        
        cur += ")";
        solve(n - 1 , cur , open - 1);
        cur.pop_back();
        
    }
    
    vector<string> generateParenthesis(int n) {
        string cur = "";
        solve(2 * n , cur , 0);
        return ans;
    }
};