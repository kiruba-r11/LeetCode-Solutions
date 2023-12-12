class Solution {
public:
    vector <vector <int>> ans;
    
    void solve(vector <int> &nums , vector <int> &cur , int target , int idx) {
        if(target == 0) {
            ans.push_back(cur);
            return;
        }
        if(target < 0) return;
        
        for(int i = idx; i < nums.size(); i++) {
            cur.push_back(nums[i]);
            solve(nums , cur , target - nums[i] , i);
            cur.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector <int> cur;
        solve(nums , cur , target , 0);
        return ans;
    }
};