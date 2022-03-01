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
    
    int climbStairs(int n) {
        
        /*
        
        Memoization:
            O(N) time and O(N + N) space complexity
        
        */
        
        vector <int> dp(n + 1 , -1);
        return solve(n , dp);
    }
};