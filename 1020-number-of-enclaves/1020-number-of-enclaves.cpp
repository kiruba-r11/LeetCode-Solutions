class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue <pair <int , int>> q;
        for(int i = 0; i < n; i++) {
            if(grid[i][0] == 1) {
                q.push({i , 0});
                grid[i][0] = 0;
            }
            if(grid[i][m - 1] == 1) {
                q.push({i , m - 1});
                grid[i][m - 1] = 0;
            }
        }
        
        for(int j = 0; j < m; j++) {
            if(grid[0][j] == 1) {
                q.push({0 , j});
                grid[0][j] = 0;
            }
            if(grid[n - 1][j] == 1) {
                q.push({n - 1 , j});
                grid[n - 1][j] = 0;
            }
        }
        
        vector <pair <int , int>> dirs = {{0 , 1} , {0 , -1} , {1 , 0} , {-1 , 0}};
        while(!q.empty()) {
            int count = q.size();
            for(int i = 0; i < count; i++) {
                pair <int , int> node = q.front();
                q.pop();
                
                for(auto dir: dirs) {
                    int x = dir.first + node.first;
                    int y = dir.second + node.second;
                    
                    if(x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 1) {
                        grid[x][y] = 0;
                        q.push({x , y});
                    }
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) ans++;
            }
        }
        
        return ans;
    }
};