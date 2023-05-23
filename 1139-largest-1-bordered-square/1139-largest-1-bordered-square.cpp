class Solution {
public:
    bool isValid(vector <vector <int>> &grid , int i , int j , int cnt , int n , int m) {
        if((j + cnt - 1 < m) && (i + cnt - 1 < n)) return true;
        return false;
    }
    
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        int ans = 0;
        
        vector <vector <int>> rcnt(n , vector <int> (m)) , bcnt(n , vector <int> (m));
        
        for(int i = n - 1; i >= 0; i--) {
            rcnt[i][m - 1] = grid[i][m - 1];
            for(int j = m - 2; j >= 0; j--) {
                if(grid[i][j] != 0) rcnt[i][j] = rcnt[i][j + 1] + grid[i][j];
            }
        }
        
        for(int j = m - 1; j >= 0; j--) {
            bcnt[n - 1][j] = grid[n - 1][j];
            for(int i = n - 2; i >= 0; i--) {
                if(grid[i][j] != 0) bcnt[i][j] = bcnt[i + 1][j] + grid[i][j];
            }
        }
        
        for(int cnt = 1; cnt <= min(n , m); cnt++) {
            bool check = false;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(isValid(grid , i , j , cnt , n , m)) {
                        bool top = rcnt[i][j] >= cnt;
                        bool bottom = rcnt[i + cnt - 1][j] >= cnt;
                        bool left = bcnt[i][j] >= cnt;
                        bool right = bcnt[i][j + cnt - 1] >= cnt;
                        
                        if(top && bottom && left && right) {
                            check = true;
                            ans = cnt * cnt;
                        }
                    }
                    if(check) break;
                }
                if(check) break;
            }
        }
        
        return ans;
    }
};