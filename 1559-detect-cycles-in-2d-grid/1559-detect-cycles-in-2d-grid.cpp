class Solution {
public:
    vector <pair <int , int>> dirs = {{0 , 1} , {0 , -1} , {1 , 0} , {-1 , 0}};
    bool dfs(vector <vector <char>> &grid , int i , int j , int pi , int pj , vector <vector <int>> &visited , char ch) {
    
        int n = grid.size();
        int m = grid[0].size();
        
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != ch) return false;
        if(visited[i][j] == true) return true;
        
        visited[i][j] = true;
        for(auto dir: dirs) {
            int x = dir.first + i;
            int y = dir.second + j;
            
            if(x == pi && y == pj) continue;
            
            bool iscycle = dfs(grid , x , y , i , j , visited , ch);
            if(iscycle) return true;
        }
        
        return false;
    }
    
    bool bfs(vector <vector <char>> &grid , int i , int j , int pi , int pj , vector <vector <int>> &visited , char ch) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        queue <vector <int>> q;
        q.push({i , j , pi , pj});
        
        visited[i][j] = true;
        
        while(!q.empty()) {
            int count = q.size();
            for(int it = 0; it < count; it++) {
                vector <int> node = q.front();
                q.pop();
                
                int ci = node[0];
                int cj = node[1];
                int cpi = node[2];
                int cpj = node[3];
                
                for(auto dir: dirs) {
                    int x = dir.first + ci;
                    int y = dir.second + cj;
                     
                    if(x >= 0 && y >= 0 && x <= n - 1 && y <= m - 1 && grid[x][y] == ch) {
                        if(visited[x][y] == false) {
                            visited[x][y] = true;
                            q.push({x , y , ci , cj});
                        } else {
                            if(x != cpi || y != cpj) return true;
                        }
                    }
                }
            }
        }
     
        return false;
    }
    
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector <vector <int>> visited(n , vector <int> (m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(visited[i][j] == false) {
                    // bool iscycle = dfs(grid , i , j , -1 , -1 , visited , grid[i][j]);
                    bool iscycle = bfs(grid , i , j , -1 , -1 , visited , grid[i][j]);
                    if(iscycle) return true;
                }
            }
        }
        
        return false;
    }
};