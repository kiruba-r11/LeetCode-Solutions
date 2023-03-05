class Solution {
public:
    int mod = 1e9 + 7;
    int solve(int target , int i , vector <vector <int>> &types , vector <vector <int>> &dp) {
        
        if(target == 0) return 1;
        if(types.size() == i) return 0;
        
        if(dp[target][i] != -1) return dp[target][i];
        
        long long ans = 0;
        for(int j = 0; j <= types[i][0]; j++) {
            if(target - j * types[i][1] >= 0) {
                ans += solve(target - j * types[i][1] , i + 1 , types , dp);    
                ans %= mod;
            }
        }
        
        return dp[target][i] = (int)ans;
    }
    
    int solve(vector <vector <int>> &types , int target) {
        
        int n = types.size();
        vector <vector <int>> dp(target + 1 , vector <int> (n + 1 , 0));
        
        for(int i = 0; i <= n; i++) dp[0][i] = 1;
        
        for(int i = 1; i <= target; i++) {
            for(int j = n - 1; j >= 0; j--) {
                for(int k = 0; k <= types[j][0]; k++) {
                    if(i - k * types[j][1] >= 0) {
                        dp[i][j] += dp[i - k * types[j][1]][j + 1];
                        dp[i][j] %= mod;
                    }
                }
            }
        }
        
        return dp[target][0];
    }
    
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        // int n = types.size();
        // vector <vector <int>> dp(target + 1 , vector <int> (n , -1));
        // int ans = solve(target , 0 , types , dp);
        int ans = solve(types , target);
        return ans;
    }
};