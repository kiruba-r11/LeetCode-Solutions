class Solution {
public:
    int mod = 1e9 + 7;
    
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size() , m = grid[0].size();
        vector <vector <vector <int>>> dp(n , vector <vector <int>> (m , vector <int> (k , 0)));
        
        dp[n - 1][m - 1][(k - grid[n - 1][m - 1] % k) % k] = 1;
        
        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                if(i == n - 1 && j == m - 1) continue;
                for(int sum = 0; sum < k; sum++) {
                    long long down = 0 , right = 0;
                    
                    if(i + 1 < n) down = dp[i + 1][j][(sum + grid[i][j]) % k];
                    if(j + 1 < m) right = dp[i][j + 1][(sum + grid[i][j]) % k];
                    
                    long long ans = (down % mod + right % mod) % mod;
                    dp[i][j][sum] = (int)ans;
                }
            }
        }
        
        return dp[0][0][0];
    }
};