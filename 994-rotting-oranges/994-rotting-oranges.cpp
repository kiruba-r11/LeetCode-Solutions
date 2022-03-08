class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int time = -1 , cnt = 0;
        int n = grid.size() , m = grid[0].size();
        
        queue <pair <int , int>> q;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2)
                    q.push({i , j});
                if(grid[i][j] == 1)
                    cnt++;
            }
        }
        
        vector <pair <int , int>> dirs = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};
        
        while(!q.empty()) {
            
            int count = q.size();
            for(int it = 0; it < count; it++) {
                
                pair <int , int> node = q.front();
                q.pop();
                
                for(auto dir: dirs) {
                    int ni = node.first + dir.first;
                    int nj = node.second + dir.second;
                    
                    if(ni >= 0 && nj >= 0 && ni < n && nj < m && grid[ni][nj] == 1) {
                        cnt--;
                        q.push({ni , nj});
                        grid[ni][nj] = 2;
                    }
                }
            }
            
            time++;
        }
        
        if(cnt != 0) return -1;
        
        return time == -1 ? 0 : time;
    }
};