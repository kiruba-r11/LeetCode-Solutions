class Solution {
public:
    void solve(int k , int n , int i , vector <int> &cur , vector <vector <int>> &ans , vector <bool> &used) {
        
        if(k == 0 || n == 0) {
            if(k == 0 && n == 0) ans.push_back(cur);
            return;
        }
        
        for(int elem = i; elem <= 9; elem++) {
            if(used[elem] == false && elem <= n) {
                
                used[elem] = true;
                cur.push_back(elem);
                
                solve(k - 1 , n - elem , elem , cur , ans , used);
                
                cur.pop_back();
                used[elem] = false;
            }
        }
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector <int> cur;
        vector <bool> used(10 , false);
        vector <vector <int>> ans;
        
        solve(k , n , 1 , cur , ans , used);
        
        return ans;
    }
};