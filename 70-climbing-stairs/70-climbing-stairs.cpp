class Solution {
public:
    
    int solve(int n , vector <int> &dp) {
    
        if(n == 0) return 1;
        if(n < 0) return 0;
        
        if(dp[n] != -1) return dp[n];
        
        int climbOne = solve(n - 1 , dp);
        int climbTwo = solve(n - 2 , dp);
        
        return dp[n] = climbOne + climbTwo;
    }
    
    int solve(int n) {
        
//         vector <int> dp(n + 1);
        
//         dp[0] = 1;
        
        int climbOne = 1 , climbTwo = 0 , cur = 0;
        
        for(int i = 1; i <= n; i++) {
//             int climbOne = dp[i - 1];
//             int climbTwo = i >= 2 ? dp[i - 2] : 0;
            
//             dp[i] = climbOne + climbTwo;
            
            cur = climbOne + climbTwo;
            climbTwo = climbOne;
            climbOne = cur;
        }
        
        // return dp[n];
        return climbOne;
    }
    
    int climbStairs(int n) {
        
        /*
        
        Memoization:
            O(N) time and O(N + N) space complexity
            
        Tabulation:
            O(N) time and O(N) space complexity
            
        Space Optimization:
            O(N) time and O(1) space complexity
        
        */
        
//         vector <int> dp(n + 1 , -1);
//         return solve(n , dp);
        
        return solve(n);
    }
};