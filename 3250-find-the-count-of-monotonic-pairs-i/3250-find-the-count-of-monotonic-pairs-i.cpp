class Solution {
public:
    int mod = 1e9 + 7;
    int solve(vector <int> &nums , int i , int arr1 , vector <vector <int>> &dp) {
        
        if(i == nums.size()) return 1;
        if(dp[i][arr1] != -1) return dp[i][arr1];
            
        long long ans = 0;
        
        for(int k = 0; k <= nums[i]; k++) {
            long long temp = 0;
            if((i == 0) || (k >= arr1 && (nums[i] - k) <= (nums[i - 1] - arr1))) temp = solve(nums , i + 1 , k , dp);
            
            ans = (ans % mod + temp % mod) % mod;
        }
        
        return dp[i][arr1] = ans;
    }
    
    int solve(vector <int> &nums) {
        int n = nums.size();
        vector <vector <vector <int>>> dp(n + 1 , vector <vector <int>> (51 , vector <int> (51 , -1)));
        
        for(int i = 0; i <= 50; i++) {
            for(int j = 0; j <= 50; j++) {
                dp[n][i][j] = 1;
            }
        }
        
        for(int i = n - 1; i >= 0; i--) {
            for(int arr1 = 0; arr1 <= 50; arr1++) {
                for(int arr2 = 0; arr2 <= 50; arr2++) {
                    long long ans = 0;
                    for(int k = 0; k <= nums[i]; k++) {
                        long long temp = 0;
                        if((i == 0) || (k >= arr1 && (nums[i] - k) <= arr2)) temp = dp[i + 1][k][nums[i] - k];
                        
                        ans = (ans % mod + temp % mod) % mod;
                    }
                    
                    dp[i][arr1][arr2] = ans;
                }
            }
        }
        
        return dp[0][0][50];
    }
    
    int solve_optimised(vector <int> &nums) {
        int n = nums.size();
        vector <vector <int>> next(51 , vector <int> (51)) , cur(51 , vector <int> (51));
        
        for(int i = 0; i <= 50; i++) {
            for(int j = 0; j <= 50; j++) {
                next[i][j] = 1;
            }
        }
        
        for(int i = n - 1; i >= 0; i--) {
            for(int arr1 = 0; arr1 <= 50; arr1++) {
                for(int arr2 = 0; arr2 <= 50; arr2++) {
                    long long ans = 0;
                    for(int k = 0; k <= nums[i]; k++) {
                        long long temp = 0;
                        if((i == 0) || (k >= arr1 && (nums[i] - k) <= arr2)) temp = next[k][nums[i] - k];
                        
                        ans = (ans % mod + temp % mod) % mod;
                    }
                    
                    cur[arr1][arr2] = ans;
                }
            }
            next = cur;
        }
        
        return next[0][50];
    }
    
    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
        vector <vector <int>> dp(n , vector <int> (55 , -1));
        return solve(nums , 0 , 0 , dp);
        
        // return solve(nums);
        // return solve_optimised(nums);
    }
};