class Solution {
public:
    int solve(vector <int> &nums , int i , int k , vector <int> &dp) {
    
        if(i == nums.size()) return 1;
        
        int dont_pick = 0 , do_pick = 0;
        
        // don't pick
        dont_pick = solve(nums , i + 1 , k , dp);
        
        // pick this element (with condition)
        if(nums[i] < k || (dp[nums[i] - k] == 0)) {
            dp[nums[i]] = 1;
            do_pick = solve(nums , i + 1 , k , dp);
            dp[nums[i]] = 0;
        }
        
        return dont_pick + do_pick;
    }
    
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        vector <int> dp(1001 , 0);
        return solve(nums , 0 , k , dp) - 1;
    }
};