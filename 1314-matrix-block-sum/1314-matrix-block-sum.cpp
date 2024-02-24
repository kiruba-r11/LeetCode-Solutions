class Solution {
public:
    bool inbounds(int n , int m , int row , int col) {
        if(row >= 0 && row < n && col >= 0 && col < m) return true;
        return false;
    }
    
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector <vector <int>> ans(n , vector <int> (m));
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < m; j++) {
                mat[i][j] += mat[i][j - 1];
            }
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 1; j < n; j++) {
                mat[j][i] += mat[j - 1][i];
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int r1 = (i - k) >= 0 ? (i - k) : 0;
                int r2 = (i + k) < n ? (i + k) : n - 1;
                int c1 = (j - k) >= 0 ? (j - k) : 0;
                int c2 = (j + k) < m ? (j + k) : m - 1;
                
                int sum = mat[r2][c2];
                if(inbounds(n , m , r1 - 1 , c1 - 1)) sum += mat[r1 - 1][c1 - 1];
                if(inbounds(n , m , r2 , c1 - 1)) sum -= mat[r2][c1 - 1];
                if(inbounds(n , m , r1 - 1 , c2)) sum -= mat[r1 - 1][c2];
                
                ans[i][j] = sum;
            }
        }
        
        return ans;
    }
};