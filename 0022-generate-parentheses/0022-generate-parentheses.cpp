class Solution {
public:
    void generate(int n , int open , string &cur , vector <string> &ans) {
        
        if(open < 0) return;
        if(n == 0) {
            if(open != 0) return;
            ans.push_back(cur);
            return;
        }
        
        // open
        cur += "(";
        generate(n - 1 , open + 1 , cur , ans);
        cur.pop_back();
        
        // close
        cur += ")";
        generate(n - 1 , open - 1 , cur , ans);
        cur.pop_back();
        
    }
    vector<string> generateParenthesis(int n) {
        string cur = "";
        vector <string> ans;
        generate(2 * n , 0 , cur , ans);
        return ans;
    }
};