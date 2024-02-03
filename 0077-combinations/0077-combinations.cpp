class Solution {
public:
    void combination(int n , int k , int idx , vector <int> &cur , vector <vector <int>> &ans) {
        
        if(k == 0) {
            ans.push_back(cur);
            return;
        }
        
        for(int i = idx; i <= n; i++) {
            cur.push_back(i);
            combination(n , k - 1 , i + 1 , cur , ans);
            cur.pop_back();
        }
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector <int> cur;
        vector <vector <int>> ans;
        combination(n , k , 1 , cur , ans);
        return ans;
    }
};