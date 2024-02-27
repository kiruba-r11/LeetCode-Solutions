class Solution {
public:
    vector <pair <int , int>> dirs = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};
    
    int dfs(vector <vector <int>> &grid , int row , int col , int &free) {
    
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || 
           grid[row][col] == -1 || grid[row][col] == 1) return 0;
        
        if(grid[row][col] == 2) {
            if(free == 0) return 1;
            return 0;
        }
        
        int ans = 0;
        grid[row][col] = -1;
        free--;
        
        for(auto dir: dirs) {
            int x = dir.first;
            int y = dir.second;
            
            ans += dfs(grid , x + row , y + col , free);
        } 
        
        grid[row][col] = 0;
        free++;
        
        return ans;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        int free = 0 , row = -1 , col = -1;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    row = i;
                    col = j;
                } 
                if(grid[i][j] == 0) {
                    free++;
                }
            }
        }

        int ans = 0;
        for(auto dir: dirs) {
            int x = dir.first;
            int y = dir.second;
            
            ans += dfs(grid , row + x , col + y , free);
        }

        return ans;
    }
};