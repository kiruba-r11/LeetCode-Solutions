class Solution {
public:
    int dp[10001][7][7];
    int mod = 1e9 + 7;
    int solve(int n , int prev1 , int prev2) {
        
        if(n == 0) return 1;
        
        if(dp[n][prev1][prev2] != -1) return dp[n][prev1][prev2];
        
        int ans = 0;
        for(int i = 1; i <= 6; i++) {
            if(i != prev1 && i != prev2 && (prev2 == 0 || __gcd(i , prev2) == 1)) {
                ans = (ans + solve(n - 1 , prev2 , i)) % mod;
            }
        }
        
        return dp[n][prev1][prev2] = ans;
    }
    
    int solve(int n) {
        
        for(int i = 0; i <= 6; i++) {
            for(int j = 0; j <= 6; j++) {
                dp[0][i][j] = 1;
            }
        }
        
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= 6; j++) {
                for(int k = 0; k <= 6; k++) {
                    int ans = 0;
                    for(int m = 1; m <= 6; m++) {
                        if(m != j && m != k && (k == 0 || __gcd(m, k) == 1)) {
                            ans = (ans + dp[i - 1][k][m]) % mod;
                        }
                    }
                    dp[i][j][k] = ans;
                }
            }
        }
        
        return dp[n][0][0];
    }
    
    int distinctSequences(int n) {
        for(int i = 0; i <= 10000; i++) {
            for(int j = 0; j <= 6; j++) {
                for(int k = 0; k <= 6; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }
        // return solve(n , 0 , 0);
        return solve(n);
    }
};