class Solution {
public:
    class Graph {
    public:
        int i;
        int j;
        int wt;
        Graph(int i , int j , int wt) {
            this->i = i;
            this->j = j;
            this->wt = wt;
        }
    };
    
    struct compareWeight {
        bool operator() (Graph const& g1 , Graph const& g2) {
            return g1.wt > g2.wt;
        }
    };
    
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        vector <vector <bool>> visited(n , vector <bool> (m , false));
        
        priority_queue <Graph , vector <Graph> , compareWeight> q;
        vector <pair <int , int>> dirs = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};
        
        q.push(Graph(0 , 0 , 0));
        visited[0][0] = true;
        
        while(!q.empty()) {
            int count = q.size();
            for(int it = 0; it < count; it++) {
                
                int ki = q.top().i;
                int kj = q.top().j;
                int wt = q.top().wt;
                
                if(ki == n - 1 && kj == m - 1) return wt;
                
                q.pop();
                
                for(auto dir: dirs) {
                    int ni = dir.first + ki;
                    int nj = dir.second + kj;
                    
                    if(ni >= 0 && ni < n && nj >= 0 && nj < m && !visited[ni][nj]) {
                            visited[ni][nj] = true;
                            q.push(Graph(ni , nj , wt + grid[ni][nj]));
                    }
                }
            }
        }
        return 0;
    }
};