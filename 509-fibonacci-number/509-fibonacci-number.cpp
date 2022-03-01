class Solution {
public:
    int fibonacci(int n , vector <int> &dp) {
        if(n <= 1) return n;
        return dp[n] = fibonacci(n - 1 , dp) + fibonacci(n - 2 , dp);
    }
    int fib(int n) {
        
        /*
        
        Memoization:
            O(N) time and O(N + N) space complexity
        
        */
        
        vector <int> dp(n + 1 , -1);
        return fibonacci(n , dp);
    }
};