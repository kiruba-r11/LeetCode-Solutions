class Solution {
public:
    
    vector <pair <int , int>> dirs = {
        {-1 , 0},
        {1 , 0},
        {0 , -1},
        {0 , 1},
        {-1 , -1},
        {1 , -1},
        {-1 , 1},
        {1 , 1}
    };
    
    int bfs(vector <vector <int>> &grid) {
        
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;
        
        queue <pair <int , int>> q;
        q.push({0 , 0});
        grid[0][0] = 1;
        
        int cost = 1;
        while(!q.empty()) {
            int count = q.size();
            for(int it = 0; it < count; it++) {
                pair <int , int> node = q.front();
                q.pop();
                
                if(node.first == n - 1 && node.second == n - 1) return cost;
                
                for(auto dir: dirs) {
                    int ni = dir.first + node.first;
                    int nj = dir.second + node.second;
                    
                    if(ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] != 1) {
                        grid[ni][nj] = 1;
                        q.push({ni , nj});
                    }
                }
            }
            cost++;
        }
        
        return -1;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        return bfs(grid);
    }
};