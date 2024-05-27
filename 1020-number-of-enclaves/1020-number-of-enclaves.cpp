class Solution {
public:
    vector <pair <int , int>> dirs = {{0 , 1} , {0 , -1} , {1 , 0} , {-1 , 0}};
    void dfs(vector <vector <int>> &grid , int row , int col) {
        int n = grid.size();
        int m = grid[0].size();
        
        if(row < 0 || col < 0 || row >= n || col >= m || grid[row][col] == 0) return;
        
        grid[row][col] = 0;
        for(auto dir: dirs) {
            int x = dir.first + row;
            int y = dir.second + col;
            
            dfs(grid , x , y);
        }
    }
    
    void helper_row(vector <vector <int>> &grid , int row) {
        int m = grid[0].size();
        for(int j = 0; j < m; j++) {
            if(grid[row][j] == 1) {
                dfs(grid , row , j);
            }
        }
    }
    
    void helper_col(vector <vector <int>> &grid , int col) {
        int n = grid.size();
        for(int i = 0; i < n; i++) {
            if(grid[i][col] == 1) {
                dfs(grid , i , col);
            }
        }
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        helper_row(grid , 0);
        helper_row(grid , n - 1);
        helper_col(grid , 0);
        helper_col(grid , m - 1);
        
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) ans++;
            }
        }
        
        return ans;
    }
};