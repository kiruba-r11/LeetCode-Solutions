class Solution {
public:
    
    int solve(vector <vector <int>> &grid , int i , int j , int x , int y , int cellsVisited , int cells) {
        
        if(i == x && j == y) {
            if(cellsVisited == cells)
                return 1;
            else
                return 0;
        }
        
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == -1)
            return 0;
        
        // make a choice
        grid[i][j] = -1;
        
        // explore all four paths
        int up = solve(grid , i - 1 , j , x , y , cellsVisited + 1 , cells); // up
        int down = solve(grid , i + 1 , j , x , y , cellsVisited + 1 , cells); // down
        int left = solve(grid , i , j - 1 , x , y , cellsVisited + 1 , cells); // left
        int right = solve(grid , i , j + 1 , x , y , cellsVisited + 1 , cells); // right
        
        // remove the choice made
        grid[i][j] = 0;
        
        return up + down + left + right;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int startRow , endRow , startCol , endCol;
        int cells = 2;
        
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    startRow = i;
                    startCol = j;
                } else if(grid[i][j] == 2) {
                    endRow = i;
                    endCol = j;
                } else if(grid[i][j] == 0) {
                    cells++;
                }
            }
        }
        
        int ans = solve(grid , startRow , startCol , endRow , endCol , 1 , cells);
        return ans;
    }
};