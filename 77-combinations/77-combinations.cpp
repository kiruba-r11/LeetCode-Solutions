class Solution {
public:
    
    void solve(vector <int> &nums , int k , vector <int> &cur , vector <vector <int>> &ans , int start) {
        
        if(k == 0) {
            ans.push_back(cur);
            return;
        }
        
        for(int i = start; i < nums.size(); i++) {
            cur.push_back(nums[i]);    
            solve(nums , k - 1 , cur , ans , i + 1);
            cur.pop_back();
        }
        
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector <int> nums(n , -1);
        
        for(int i = 0; i < n; i++) {
            nums[i] = i + 1;
        }
        
        vector <int> cur;
        vector <vector <int>> ans;
        
        solve(nums , k , cur , ans , 0);
        
        return ans;
    }
};