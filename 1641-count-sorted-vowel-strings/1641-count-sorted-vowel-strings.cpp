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
    int countVowelStrings(int n) {
        vector <vector <int>> dp(n + 1 , vector <int> (6 , -1));
        return solve(n , 1 , dp);
    }
};