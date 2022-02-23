class Solution {
public:
    vector <pair <int , int>> dirs = {{-1 , 0} , {1 , 0} , {0 , 1} , {0 , -1}};
    
    int maxDistance(vector<vector<int>>& grid) {
        
        /*
        
        O(N * N) time and O(N) space complexity
        Idea -> 
            1. Given question:
                Find the 0 which has the maximum distance to 1.
            2. Reverse Thoughts:
                - Let's perform multi-sourced BFS from 1. 
                - Surely it will stop at the 0, that is at maximum distance from all the 1's.
                - That distance is the required answer
        
        */
        
        int n = grid.size();
        
        queue <pair <int , int>> q;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) q.push({i , j});
            }
        }
        
        if(q.size() == 0) return -1;
        if(q.size() == n * n) return -1;
        
        int dist = -1;
        
        while(!q.empty()) {
            
            int count = q.size();
            for(int it = 0; it < count; it++) {
                pair <int , int> node = q.front();
                q.pop();
                
                for(auto dir: dirs) {
                    int x = dir.first;
                    int y = dir.second;
                    
                    int ni = x + node.first;
                    int nj = y + node.second;
                    
                    if(ni >= 0 && nj >= 0 && ni < n && nj < n && grid[ni][nj] == 0) {
                        grid[ni][nj] = 1;
                        q.push({ni , nj});
                    }
                }
            }
            dist++;
        }
        
        return dist;
    }
};