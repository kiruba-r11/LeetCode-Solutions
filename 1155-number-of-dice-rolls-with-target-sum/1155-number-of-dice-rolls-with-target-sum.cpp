class Solution {
private:
    int mod = 1000000007;    
public:
    int solve(int d , int f , int target , vector <vector <int>> &dp) {
        if(d < 0) return 0;
        if(target < 0) return 0;
        if(target == 0 && d == 0) return 1;
        
        if(dp[d][target] != -1) return dp[d][target];
        
        int ans = 0;
        for(int i = 1; i <= f; i++) {
            ans = ((ans % mod) + (solve(d - 1 , f , target - i , dp)) % mod) % mod;
        }
        
        return dp[d][target] = ans;
    }
    int numRollsToTarget(int d, int f, int target) {
        vector <vector <int>> dp(d + 1 , vector <int> (target + 1 , -1));
        return solve(d , f , target , dp);
    }
};