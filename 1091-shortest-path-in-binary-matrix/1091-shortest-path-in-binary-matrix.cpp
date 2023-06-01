class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        if(grid[0][0] == 1 || grid[n - 1][m - 1] == 1) return -1;
        
        queue <pair <int , int>> q;
        q.push({0 , 0});
        int dist = 1;
        
        vector <pair <int , int>> dirs = {
            {1 , 0} , {-1 , 0} , {0 , 1} , {0 , -1} , 
            {1 , 1} , {-1 , 1} , {1 , -1} , {-1 , -1}
        };
        
        vector <vector <bool>> visited(n , vector <bool> (m));
        visited[0][0] = true;
        
        while(!q.empty()) {
            int cnt = q.size();
            for(int it = 0; it < cnt; it++) {
                int ci = q.front().first;
                int cj = q.front().second;
                
                q.pop();
                
                if(ci == n - 1 && cj == m - 1) return dist;
                
                for(auto dir: dirs) {
                    int ni = dir.first + ci;
                    int nj = dir.second + cj;
                    
                    if(ni >= 0 && ni < n && nj >= 0 && nj < m) {
                        if(!visited[ni][nj] && grid[ni][nj] == 0) {
                            q.push({ni , nj});
                            visited[ni][nj] = true;
                        }
                    }
                }
            }
            dist++;
        }
        
        return -1;
    }
};