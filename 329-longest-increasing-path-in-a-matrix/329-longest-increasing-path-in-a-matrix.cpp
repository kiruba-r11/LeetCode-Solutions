class Solution {
public:
    vector <pair <int , int>> dirs = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};
    int solve(vector <vector <int>> &matrix , int i , int j , vector <vector <int>> &dp) {
        
        int n = matrix.size() , m = matrix[0].size();
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = 0;
        for(auto dir: dirs) {
            int ni = dir.first + i;
            int nj = dir.second + j;
            
            if(ni >= 0 && nj >= 0 && ni < n && nj < m && matrix[i][j] < matrix[ni][nj]) {
                ans = max(ans , solve(matrix , ni , nj , dp));
            }
        }
        
        return dp[i][j] = ans + 1;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size() , m = matrix[0].size();
        vector <vector <int>> dp(n , vector <int> (m , -1));
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans = max(ans , solve(matrix , i , j , dp));
            }
        }
        
        return ans;
    }
};