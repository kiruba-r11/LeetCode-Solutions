class Solution {
public:
    
    int solve(vector <int> &nums , int index , vector <int> &dp) {
        
        if(index >= nums.size() - 1) return 0;
        
        if(dp[index] != -1) return dp[index];
        
        int ans = (int)1e6;
        
        // All possible jumps that can be made from this position
        for(int i = 1; i <= nums[index]; i++) {
            
            ans = min(ans , 1 + solve(nums , index + i , dp));
        }
        
        return dp[index] = ans;
    }
    
    int solve(vector <int> &nums , int index) {
        
        int n = nums.size();
        vector <int> dp(n , 0);
        
        for(int i = n - 2; i >= 0; i--) {
            
            int ans = (int)1e6;
            for(int j = 1; j <= nums[i]; j++) {
                
                int temp = 1 + ((i + j) <= n - 2 ? dp[i + j] : 0);
                ans = min(ans , temp);
            }
            dp[i] = ans;
        }
        
        return dp[0];
    }
    
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        // vector <int> dp(n , -1);
        
        // return solve(nums , 0 , dp);
        return solve(nums , 0);
    }
};