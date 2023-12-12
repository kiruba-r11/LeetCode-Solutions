class Solution {
public:
    vector <vector <int>> ans;
    void solve(vector <int> &cur , int n , int idx , int k) {
        
        if(k == 0) {
            ans.push_back(cur);
            return;
        }
        
        for(int i = idx; i <= n; i++) {
            cur.push_back(i);
            solve(cur , n , i + 1 , k - 1);
            cur.pop_back();
        }
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector <int> cur;
        solve(cur , n , 1 , k);
        return ans;
    }
};