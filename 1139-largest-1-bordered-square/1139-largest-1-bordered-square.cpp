class Solution {
public:
//     bool checkRow(vector <vector <int>> &grid , int s , int e , int r) {
//         for(int k = s; k < e; k++) {
//             if(grid[r][k] != 1) {
//                 return false;
//             }
//         }
        
//         return true;
//     }
    
//     bool checkCol(vector <vector <int>> &grid , int s , int e , int r) {
//         for(int k = s; k < e; k++) {
//             if(grid[k][r] != 1) {
//                 return false;
//             }
//         }
        
//         return true;
//     }
    
    bool isValid(vector <vector <int>> &grid , int i , int j , int cnt , int n , int m) {
        if((j + cnt - 1 < m) && (i + cnt - 1 < n)) {
            if((grid[i][j] == 1) && (grid[i][j + cnt - 1] == 1) && 
               (grid[i + cnt - 1][j] == 1) && (grid[i + cnt - 1][j + cnt - 1] == 1)) return true;
            return false;
        }
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
        
//         for(int i = 0; i < n; i++) {
//             for(int j = 0; j < m; j++) {
//                 cout << rcnt[i][j] << " ";
//             }
//             cout << endl;
//         }
        
//         cout << endl;
        
//         for(int i = 0; i < n; i++) {
//             for(int j = 0; j < m; j++) {
//                 cout << bcnt[i][j] << " ";
//             }
//             cout << endl;
//         }
        
//         cout << endl;
        
        for(int cnt = 1; cnt <= min(n , m); cnt++) {
            bool check = false;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(isValid(grid , i , j , cnt , n , m)) {
                        bool top = rcnt[i][j] >= cnt;
                        bool bottom = rcnt[i + cnt - 1][j] >= cnt;
                        bool left = bcnt[i][j] >= cnt;
                        bool right = bcnt[i][j + cnt - 1] >= cnt;
                        // bool top = checkRow(grid , j , j + cnt , i);
                        // bool bottom = checkRow(grid , j , j + cnt , i + cnt - 1);
                        // bool left = checkCol(grid , i , i + cnt , j);
                        // bool right = checkCol(grid , i , i + cnt , j + cnt - 1);
                        
                        if(top && bottom && left && right) {
                            // if(cnt == 3) cout << i << " " << j << endl;
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