class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        vector <vector <int>> dist(n , vector <int> (m , INT_MAX));
        vector <pair <int , int>> dirs = {{0 , 1} , {0 , -1} , {1 , 0} , {-1 , 0}};
        priority_queue <vector <int> , vector <vector <int>> , greater <vector <int>>> pq;
        
        pq.push({0 , 0 , 0});
        dist[0][0] = 0;        
        
        while(!pq.empty()) {
            int nd = pq.top()[0];
            int ni = pq.top()[1];
            int nj = pq.top()[2];
            
            pq.pop();
            
            if(ni == n - 1 && nj == m - 1) return dist[n - 1][m - 1];
            
            for(auto dir: dirs) {
                int x = dir.first + ni;
                int y = dir.second + nj;
                
                if(x >= 0 && x < n && y >= 0 && y < m) {
                    int d = max(abs(heights[x][y] - heights[ni][nj]) , nd);
                    if(d < dist[x][y]) {
                        dist[x][y] = d;
                        pq.push({d , x , y});
                    }
                }
            }
        }
        
        return dist[n - 1][m - 1];
    }
};