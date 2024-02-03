class Solution {
public:
    void happyString(int n , string &cur , vector <string> &ans) {
        
        if(n == 0) {
            ans.push_back(cur);
            return;
        }
    
        for(int i = 'a'; i <= 'c'; i++) {
            if(cur.size() == 0 || cur.back() != i) {
                cur.push_back(i);
                happyString(n - 1 , cur , ans);
                cur.pop_back();
            }
        }
        
    }
    
    string getHappyString(int n, int k) {
        vector <string> ans;
        string cur = "";
        
        happyString(n , cur , ans);
        
        return ans.size() < k ? "" : ans[k - 1];
    }
};