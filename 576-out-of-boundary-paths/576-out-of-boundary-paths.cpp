class Solution {
public:
    int mod = (int)1e9 + 7;
    vector <pair <int , int>> dirs = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};
    
    int f(int m , int n , int maxMove , int i , int j , vector <vector <vector <int>>> &dp) {
        
        if(i < 0 || j < 0 || i >= m || j >= n) return 1;
        if(maxMove == 0) return 0;
        
        if(dp[i][j][maxMove] != -1) return dp[i][j][maxMove];
        
        int ans = 0;
        
        for(auto dir: dirs) {
            int x = dir.first;
            int y = dir.second;
            
            ans += f(m , n , maxMove - 1 , i + x, j + y , dp);
            ans %= mod;
        }
        
        return dp[i][j][maxMove] = ans;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector <vector <vector <int>>> dp(m , vector <vector <int>> (n , vector <int> (maxMove + 1 , -1)));
        return f(m , n , maxMove , startRow , startColumn , dp);
    }
};