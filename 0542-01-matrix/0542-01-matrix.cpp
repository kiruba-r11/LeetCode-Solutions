class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // Given: Matrix (Imaginary Graph)
        // Approach: Multisource BFS
        
        int n = mat.size();
        int m = mat[0].size();
        
        vector <vector <int>> ans(n , vector <int> (m , INT_MAX));
        vector <pair <int , int>> dirs = {{0 , 1} , {0 , -1} , {1 , 0} , {-1 , 0}};
        
        queue <pair <int , int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    q.push({i , j});
                    ans[i][j] = 0;
                }
            }
        }
        
        while(!q.empty()) {
            int count = q.size();
            for(int it = 0; it < count; it++) {
                pair <int , int> node = q.front();
                q.pop();
                
                int i = node.first;
                int j = node.second;
                
                for(auto dir: dirs) {
                    int x = dir.first + i;
                    int y = dir.second + j;
                    
                    if(x >= 0 && y >= 0 && x < n && y < m && ans[x][y] == INT_MAX) {
                        q.push({x , y});
                        ans[x][y] = ans[i][j] + 1;
                    }
                }
            }
        }
        
        return ans;
    }
};