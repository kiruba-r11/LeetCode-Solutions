class Solution {
public:
    void combination(int n , int target , int start , vector <int> &cur , vector <vector <int>> &ans) {
        
        if(cur.size() == n) {
            if(target == 0) ans.push_back(cur);
            return;
        }
        
        for(int i = start; i <= 9; i++) {
            if(target >= i) {
                cur.push_back(i);
                combination(n , target - i , i + 1 , cur , ans);
                cur.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector <vector <int>> ans;
        vector <int> cur;
        
        combination(k , n , 1 , cur , ans);
        return ans;
    }
};