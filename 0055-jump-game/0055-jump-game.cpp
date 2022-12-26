class Solution {
public:
    
    bool solve(vector <int> &nums , int index , vector <int> &dp) {
        
        // If I reach last element, or beyond it
        if(index >= nums.size() - 1) return true;
        
        if(dp[index] != -1) return dp[index]; 
        
        // The options for me to jump at current index
        for(int i = 1; i <= nums[index]; i++) {
            if(solve(nums , index + i , dp)) return dp[index] = true;
        }
        
        return dp[index] = false;
    }
    
    int solve(vector <int> &nums , int index) {
        
        int n = nums.size();
        vector <bool> dp(n);
        
        for(int i = n - 2; i >= 0; i--) {
            for(int j = 1; j <= nums[i]; j++) {
                
                if(i + j < n - 1 && dp[i + j]) {
                    dp[i] = true;
                    break;
                }
                if(i + j >= n - 1) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[0];
    }
    
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n == 1) return true;
        
        // vector <int> dp(n , -1);
        
        return solve(nums , 0);
        
        // return solve(nums , 0 , dp);
    }
};