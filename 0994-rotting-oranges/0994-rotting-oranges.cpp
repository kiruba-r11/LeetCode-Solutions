class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // Given: Matrix (Imaginary Graph)
        // To find: No. of connected components
        // Approach: Multisource BFS
        
        queue <pair <int , int>> q;
        int fresh = 0;
        int ans = -1;
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) fresh++;
                else if(grid[i][j] == 2) q.push({i , j});
            }
        }

        vector <pair <int , int>> dirs = {{0 , 1} , {0 , -1} , {1 , 0} , {-1 , 0}};
        while(!q.empty()) {
            int count = q.size();
            for(int i = 0; i < count; i++) {
                pair <int , int> node = q.front();
                q.pop();
                
                int row = node.first;
                int col = node.second;
                
                for(auto dir: dirs) {
                    int x = dir.first + row;
                    int y = dir.second + col;
                    
                    if(x >= 0 && y >= 0 && x <= n - 1 && y <= m - 1 && grid[x][y] == 1) {
                        grid[x][y] = 2;
                        fresh--;
                        q.push({x , y});
                    }
                }
            }

            ans++;
        }
        
        return fresh == 0 ? ans == -1 ? 0 : ans : -1;
    }
};