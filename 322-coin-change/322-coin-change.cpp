class Solution {
public:
    int f(vector <int> &coins , int amount , int index , vector <vector <int>> &dp) {
        
        if(amount == 0) return 0;
        if(index == coins.size() || amount < 0) return (int)1e6;
        
        if(dp[index][amount] != -1) return dp[index][amount];
        
        int skip = 0 , choose = 0;
        
        // Skip this coin
        skip = f(coins , amount , index + 1 , dp);
        
        // Choose this coin
        choose = 1 + f(coins , amount - coins[index] , index , dp);
        
        return dp[index][amount] = min(skip , choose);
    }
    
    int f(vector <int> &coins , int amount) {
        
        int n = coins.size();
        vector <vector <int>> dp(n + 1 , vector <int> (amount + 1 , 1e6));
        
        for(int i = 0; i < amount; i++) dp[n][i] = 1e6;
        for(int i = 0; i <= n; i++) dp[i][0] = 0;
        
        for(int i = n - 1; i >= 0; i--) {
            for(int j = 0; j <= amount; j++) {
             
                int skip = dp[i + 1][j];
                int choose = (j - coins[i] < 0) ? 1e6 : 1 + dp[i][j - coins[i]];
                
                dp[i][j] = min(skip , choose);
            }
        }
        
        return dp[0][amount] == (int)1e6 ? -1 : dp[0][amount];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int index = 0;
        int n = coins.size();
//         vector <vector <int>> dp(n , vector <int> (amount + 1 , -1));
        
//         int ans = f(coins , amount , index , dp);
//         ans = (ans == (int)1e6) ? -1 : ans;
        
        int ans = f(coins , amount);
        return ans;
    }
};