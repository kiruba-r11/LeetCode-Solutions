class Solution {
public:
    vector <pair <int , int>> dirs = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};
    void dfs(vector <vector <char>> &grid , int i , int j) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0') return;
        
        grid[i][j] = '0';
        
        for(auto dir: dirs) {
            int x = dir.first;
            int y = dir.second;
            
            dfs(grid , i + x , j + y);
        }        
    }
    
    void bfs(vector <vector <char>> &grid , int i , int j) {
        
        int n = grid.size() , m = grid[0].size();
        
        queue <pair <int , int>> q;
        q.push({i , j});
        grid[i][j] = '0';
        
        while(!q.empty()) {
            
            int count = q.size();
            for(int i = 0; i < count; i++) {
                
                pair <int , int> node = q.front();
                q.pop();
            
                for(auto dir: dirs) {
                    int x = dir.first;
                    int y = dir.second;
                    
                    int ni = node.first + x;
                    int nj = node.second + y;
                    
                    if(ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == '1') {
                        grid[ni][nj] = '0';
                        q.push({ni , nj});
                    }
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size() , m = grid[0].size();
        int count = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1') {
                    count++;
                    // dfs(grid , i , j);
                    bfs(grid , i , j);
                }
            }
        }
        
        return count;
        
    }
};