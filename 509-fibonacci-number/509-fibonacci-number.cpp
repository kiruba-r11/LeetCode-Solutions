class Solution {
public:
    
    int fibonacci(int n , vector <int> &dp) {
        if(n <= 1) return n;
        return dp[n] = fibonacci(n - 1 , dp) + fibonacci(n - 2 , dp);
    }
    
    int fibonacci(int n) {
        
        if(n == 0) return 0;
        
        vector <int> dp(n + 1);
        
        dp[0] = 0;
        dp[1] = 1;
        
        for(int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        return dp[n];
    }
    
    int fib(int n) {
        
        /*
        
        Memoization:
            O(N) time and O(N + N) space complexity
            
        Tabulation: 
            O(N) time and O(N) space complexity
         
        */
        
        // vector <int> dp(n + 1 , -1);
        // return fibonacci(n , dp);
        
        return fibonacci(n);
    }
};