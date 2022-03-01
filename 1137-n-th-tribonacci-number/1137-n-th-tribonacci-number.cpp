class Solution {
public:
    int trib(int n , vector <int> &dp) {
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        
        if(dp[n] != -1) return dp[n];
        
        return dp[n] = trib(n - 1 , dp) + trib(n - 2 , dp) + trib(n - 3 , dp);
    }
    int tribonacci(int n) {
        
        /*
        
        Memoization:
            O(N) time and O(N + N) space complexity
        
        */
        
        vector <int> dp(n + 1 , -1);
        return trib(n , dp);
    }
};