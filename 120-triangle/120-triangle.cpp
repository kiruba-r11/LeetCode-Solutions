class Solution {
public:
    const int INTMAX = (int)1e5;
    
    int solve(vector <vector <int>> &triangle , int row , int col , vector <vector <int>> &dp) {
        
        if(row >= triangle.size()) return 0;
        
        if(dp[row][col] != -1) return dp[row][col];
        
        int down = INTMAX , right = INTMAX;
            
        // Go to i
        down = solve(triangle , row + 1 , col , dp);
        
        // Go to i + 1
        right = solve(triangle , row + 1 , col + 1 , dp);
        
        return dp[row][col] = min(down , right) + triangle[row][col];
    }
    
    int solve(vector <vector <int>> &triangle) {
        
        int n = triangle.size() , ans = INT_MAX;
        int m = triangle[n - 1].size();
        
        // vector <vector <int>> dp(n , vector <int> (m , INTMAX));
        vector <int> prev(m , INTMAX) , cur(m , INTMAX);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= i; j++) {
                
                int up = INTMAX , left = INTMAX;
                
                if(i == 0) up = 0 , left = 0;
                else {
                    up = prev[j];
                    if(j - 1 >= 0) left = prev[j - 1];
                }
                 
                cur[j] = min(up , left) + triangle[i][j];
            }
            prev = cur;
        }
        
        for(int i = 0; i < m; i++) {
            ans = min(ans , prev[i]);
        }
        
        return ans;
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
//         int row = 0 , col = 0;
//         int n = triangle.size() , m = triangle[n - 1].size();
        
//         vector <vector <int>> dp(n , vector <int> (m , -1));
        // return solve(triangle , row , col , dp);
        return solve(triangle);
    }
};