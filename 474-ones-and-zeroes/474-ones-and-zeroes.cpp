class Solution {
public:
    int dp[601][101][101];
    int solve(vector <pair <int , int>> &nums , int m , int n , int index) {
    
        if(index == nums.size()) return 0;
        
        if(dp[index][m][n] != -1) return dp[index][m][n];
        
        int notPick = -1e6 , pick = -1e6;
        notPick = solve(nums , m , n , index + 1);
        
        if(nums[index].first <= m && nums[index].second <= n) {
            pick = 1 + solve(nums , m - nums[index].first , n - nums[index].second , index + 1);
        }
        
        return dp[index][m][n] = max(pick , notPick);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        vector <pair <int , int>> nums(size);
        
        for(int i = 0; i < size; i++) {
            int ones = 0 , zeroes = 0;
            for(auto j: strs[i]) {
                if(j == '0') zeroes += 1;
                else ones += 1;
            }
            nums[i] = {zeroes , ones};
        }
        
        for(int i = size - 1; i >= 0; i--) {
            for(int j = 0; j <= m; j++) {
                for(int k = 0; k <= n; k++) {
                    int notPick = -1e6 , pick = -1e6;

                    notPick = dp[i + 1][j][k];

                    if(nums[i].first <= j && nums[i].second <= k) {
                        pick = 1 + dp[i + 1][j - nums[i].first][k - nums[i].second];
                    }
                    
                    dp[i][j][k] = max(pick , notPick);
                }
            }
        }
        
        return dp[0][m][n];
        // return solve(nums , m , n , 0);
    }
};