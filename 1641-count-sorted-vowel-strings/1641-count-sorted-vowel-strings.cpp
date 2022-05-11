class Solution {
public:
    int solve(int n , int prev , vector <vector <int>> &dp) {
        
        if(n == 0) return 1;
        
        if(dp[n][prev] != -1) return dp[n][prev];
        
        int ans = 0;
        for(int i = prev; i <= 5; i++) {
            ans += solve(n - 1 , i , dp);
        }
        
        return dp[n][prev] = ans;
    }
    
    int solve(int n) {
        
        vector <vector <int>> dp(n + 1 , vector <int> (6));
        for(int i = 0; i <= 5; i++) dp[0][i] = 1;
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= 5; j++) {
                int ans = 0;
                for(int k = j; k <= 5; k++) {
                    ans += dp[i - 1][k];
                }
                dp[i][j] = ans;
            }
        }
        return dp[n][1];
    }
    
    int countVowelStrings(int n) {
        // vector <vector <int>> dp(n + 1 , vector <int> (6 , -1));
        // return solve(n , 1 , dp);
        return solve(n);
    }
};