class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i = 0; i < n; i++) {
            if(grid[i][0] != 1) {
                for(int j = 0; j < m; j++) {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }
        
        for(int i = 0; i < m; i++) {
            int cnt = 0;
            for(int j = 0; j < n; j++) {
                if(grid[j][i] == 1) cnt++;
            }
            
            int leftover = n - cnt;
            if(leftover > cnt) {
                for(int j = 0; j < n; j++) {
                    grid[j][i] = 1 - grid[j][i];
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int cur = 0;
            for(int j = 0; j < m; j++) {
                cur = cur * 2 + grid[i][j];
            }
            ans += cur;
        }
        
        return ans;
    }
};