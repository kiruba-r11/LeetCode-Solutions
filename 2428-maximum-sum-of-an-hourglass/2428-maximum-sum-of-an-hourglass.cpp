class Solution {
public:
    
    bool inbounds(vector <vector <int>> &grid , int row , int col) {
        int n = grid.size();
        int m = grid[0].size();
        
        if(row + 2 >= n || col + 2 >= m) return false;
        return true;
    }
    
    int calc(vector <vector <int>> &grid , int row , int col) {
    
        if(inbounds(grid , row , col) == false) return 0;
        
        int sum = 0;
        sum += grid[row][col];
        sum += grid[row][col + 1];
        sum += grid[row][col + 2];
        sum += grid[row + 1][col + 1];
        sum += grid[row + 2][col];
        sum += grid[row + 2][col + 1];
        sum += grid[row + 2][col + 2];
        
        return sum;
    }
    
    int maxSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans = max(ans , calc(grid , i , j));
            }
        }
        
        return ans;
    }
};