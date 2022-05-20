class Solution {
public:
    int solve(vector <vector <int>> &grid , int i , int j , vector <vector <int>> &dp) {
        
        int n = grid.size() , m = grid[0].size();
        if(i == n - 1 && j == m - 1 && grid[i][j] == 0) return 1;
        if(i == n || j == m) return 0;
        if(grid[i][j] == 1) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int right = solve(grid , i + 1 , j , dp);
        int down = solve(grid , i , j + 1 , dp);
        
        return dp[i][j] = right + down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        vector <vector <int>> dp(n , vector <int> (m , -1));
        
        return solve(grid , 0 , 0 , dp);
    }
};