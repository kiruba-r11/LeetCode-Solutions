class Solution {
public:
    
    vector <pair <int , int>> dirs = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};
    
    void dfs(vector <vector <int>> &grid , int i , int j , int &count) {
        
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0) return;
        
        grid[i][j] = 0;
        count++;
        
        for(auto dir: dirs) {
            int x = dir.first;
            int y = dir.second;
            
            dfs(grid , i + x , j + y , count);
        }
        
    }
    
    void bfs(vector <vector <int>> &grid , int i , int j , int &count) {
        
        int n = grid.size() , m = grid[0].size();
        
        queue <pair <int , int>> q;
        q.push({i , j});
        grid[i][j] = 0;
        count++;
        
        while(!q.empty()) {
            int cnt = q.size();
            for(int i = 0; i < cnt; i++) {
                
                pair <int , int> node = q.front();
                q.pop();
                
                for(auto dir: dirs) {
                    int x = dir.first;
                    int y = dir.second;
                    
                    int ni = node.first + x;
                    int nj = node.second + y;
                    
                    if(ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == 1) {
                        grid[ni][nj] = 0;
                        count++;
                        q.push({ni , nj});
                    }
                }
                
            }
        }
        
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        /*
        
        O(N ^ 2) time and O(N) space complexity
        Idea -> DFS or BFS
        
        */
        
        int n = grid.size() , m = grid[0].size();
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    int count = 0;
                    // dfs(grid , i , j , count);
                    bfs(grid , i , j , count);
                    ans = max(ans , count);
                }
            }
        }
        
        return ans;
    }
};