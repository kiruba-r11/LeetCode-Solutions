class Solution {
public:
    int solve(int m , int n , vector <vector <int>> &dp) {
        if(m == 0 && n == 0) return 1;
        if(m < 0 || n < 0) return 0;
        
        if(dp[m][n] != -1) return dp[m][n];
        
        int up = solve(m - 1 , n , dp);
        int left = solve(m , n - 1 , dp);
        
        return dp[m][n] = up + left; 
    }
    
    int solve(int m , int n) {
        
        // vector <vector <int>> dp(m , vector <int> (n , 0));
        vector <int> prev(n , 0) , cur(n , 0);
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                if(i == 0 && j == 0) cur[j] = 1;
                else if(i == 0) cur[j] = cur[j - 1];
                else if(j == 0) cur[j] = prev[j];
                else cur[j] = prev[j] + cur[j - 1];
            }
            prev = cur;
        }
        
        return prev[n - 1];
    }

    int uniquePaths(int m, int n) {
        // vector <vector <int>> dp(m , vector <int> (n , -1));
        // return solve(m - 1 , n - 1 , dp);
        
        return solve(m , n);
    }
};