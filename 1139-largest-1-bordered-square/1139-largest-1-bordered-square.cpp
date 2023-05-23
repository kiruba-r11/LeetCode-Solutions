class Solution {
public:
    bool checkRow(vector <vector <int>> &grid , int s , int e , int r) {
        for(int k = s; k < e; k++) {
            if(grid[r][k] != 1) {
                return false;
            }
        }
        
        return true;
    }
    
    bool checkCol(vector <vector <int>> &grid , int s , int e , int r) {
        for(int k = s; k < e; k++) {
            if(grid[k][r] != 1) {
                return false;
            }
        }
        
        return true;
    }
    
    bool isValid(int i , int j , int cnt , int n , int m) {
        if((j + cnt - 1 < m) && (i + cnt - 1 < n)) return true;
        return false;
    }
    
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        int ans = 0;
        
        for(int cnt = 1; cnt <= min(n , m); cnt++) {
            bool check = false;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(isValid(i , j , cnt , n , m)) {
                        bool top = checkRow(grid , j , j + cnt , i);
                        bool bottom = checkRow(grid , j , j + cnt , i + cnt - 1);
                        bool left = checkCol(grid , i , i + cnt , j);
                        bool right = checkCol(grid , i , i + cnt , j + cnt - 1);
                        
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