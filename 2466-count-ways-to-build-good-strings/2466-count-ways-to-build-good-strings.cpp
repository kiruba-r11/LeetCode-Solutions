class Solution {
public:
    int mod = 1e9 + 7;
    int solve(int zero , int one , int n , vector <int> &dp) {
        if(n == 0) return 1;
        if(n < 0) return 0;
        if(n < zero && n < one) return 0;
        if(n == zero) {
            if(n >= one && n % one == 0) return 2;
            return 1;
        }
        if(n == one) {
            if(n >= zero && n % zero == 0) return 2;
            return 1;
        }
        
        if(dp[n] != -1) return dp[n];
        
        return dp[n] = ((solve(zero , one , n - zero , dp) % mod) + (solve(zero , one , n - one , dp) % mod)) % mod;
    }
    
    int countGoodStrings(int low, int high, int zero, int one) {
        
        long long ans = 0;
        vector <int> dp(high + 1 , -1);
        
        for(int i = low; i <= high; i++) {
            ans += solve(zero , one , i , dp);
            // cout << ans << " ";
            ans %= mod;
        }    
        // cout << endl;
        return ans;
    }
};