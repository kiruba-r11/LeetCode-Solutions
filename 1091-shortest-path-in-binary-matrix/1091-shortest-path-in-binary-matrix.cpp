class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        int ans = 0;
        
        if(grid[0][0] == 1) return -1;
        
        vector <pair <int , int>> dirs = {
            {-1 , -1} , {-1 , 0} , {-1 , 1} , 
            {0 , -1} , {0 , 0} , {0 , 1} , 
            {1 , -1} , {1 , 0} , {1 , 1}  
        };
        
        queue <pair <int , int>> q;
        q.push({0 , 0});
        grid[0][0] = 1;
        
        while(!q.empty()) {
            int count = q.size();
            ans++;
            for(int i = 0; i < count; i++) {
                int ni = q.front().first;
                int nj = q.front().second;
                
                q.pop();
                
                if(ni == n - 1 && nj == m - 1) return ans;
                
                for(auto dir: dirs) {
                    int x = dir.first + ni;
                    int y = dir.second + nj;
                    
                    if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 0) {
                        grid[x][y] = 1;
                        q.push({x , y});
                    }
                }
            }
        }
        
        return -1;
    }
};