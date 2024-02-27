class Solution {
public:
    bool canPlaceCol(vector <vector <int>> &grid , int row , int col) {
    
        int n = grid.size();
        for(int i = 0; i < row; i++) {
            if(grid[i][col] == 1) return false;
        }
        
        return true;
    }
    
    bool canPlaceDia(vector <vector <int>> &grid , int row , int col) {
        
        int n = grid.size();
        vector <pair <int , int>> dirs = {{-1 , 1} , {1 , -1} , {-1 , -1} , {1 , 1}};
        
        for(auto dir: dirs) {
            int x = dir.first + row;
            int y = dir.second + col;
            
            while(x >= 0 && x < n && y >= 0 && y < n) {
                if(grid[x][y] == 1) return false;
                x = dir.first + x;
                y = dir.second + y;
            }
        }
        
        return true;
    }
    
    
    bool canPlace(vector <vector <int>> &grid , int row , int col) {
        return canPlaceCol(grid , row , col) && canPlaceDia(grid , row , col);
    } 
    
    int dfs(vector <vector <int>> &grid , int row) {
    
        int n = grid.size();
        if(row == n) return 1;
        
        int ans = 0;
        
        for(int col = 0; col < n; col++) {
            if(canPlace(grid , row , col)) {
                grid[row][col] = 1;
                ans += dfs(grid , row + 1);
                grid[row][col] = 0;
            }
        }
        
        return ans;
    }
    
    int totalNQueens(int n) {
        vector <vector <int>> grid(n , vector <int> (n));
        return dfs(grid , 0);
    }
};