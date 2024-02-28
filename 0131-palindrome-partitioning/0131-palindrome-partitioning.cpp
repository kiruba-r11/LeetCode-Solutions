class Solution {
public:
    vector <string> cur;
    vector <vector <string>> ans;
    
    bool ispalindrome(string &s) {
        int i = 0 , j = s.size() - 1;
        while(i < j) {
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
    
    void solve(string &s , int idx) {
        
        if(idx == s.size()) {
            ans.push_back(cur);
            return;
        }
        
        string temp = "";
        for(int i = idx; i < s.size(); i++) {
            temp.push_back(s[i]);
            if(ispalindrome(temp)) {
                cur.push_back(temp);
                solve(s , i + 1);
                cur.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        solve(s , 0);
        return ans;
    }
};