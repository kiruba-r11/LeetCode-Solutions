class Solution {
public:
    
    int maximumScore(vector<int>& nums, vector<int>& muls) {
        
        int m = muls.size() , n = nums.size(); 
        vector <vector <int>> dp(m + 1 , vector <int> (m + 1));
        
        for(int i = m - 1; i >= 0; i--) {
            for(int j = i; j >= 0; j--) {
                int start = dp[i + 1][j + 1] + nums[j] * muls[i];
                int end = dp[i + 1][j] + nums[(n - 1) - (i - j)] * muls[i];
                
                dp[i][j] = max(start , end);
            }
        }
        
        return dp[0][0];

    }
};