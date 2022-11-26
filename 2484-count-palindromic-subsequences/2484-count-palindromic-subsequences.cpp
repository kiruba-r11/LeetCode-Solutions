class Solution {
public:
    int mod = 1e9 + 7;
    int dp[10001][6][11][11];
    
    int solve(int ind , int size , int first , int second , string &s) {
    
        if(size == 5) return 1;
        if(ind == s.size()) return 0;
        
        if(dp[ind][size][first][second] != -1) return dp[ind][size][first][second];
        
        long long res = 0;
        res += solve(ind + 1 , size , first , second , s);
        res %= mod;
        
        if(size == 0) {
            res += solve(ind + 1 , size + 1 , s[ind] - '0' , second , s);
            res %= mod;
        } else if(size == 1) {
            res += solve(ind + 1 , size + 1 , first , s[ind] - '0' , s);
            res %= mod;
        } else if(size == 2) {
            res += solve(ind + 1 , size + 1 , first , second , s);
            res %= mod;
        } else if(size == 3) {
            if(s[ind] - '0' == second) {
                res += solve(ind + 1 , size + 1 , first , second , s);
                res %= mod;
            }
        } else if(size == 4) {
            if(s[ind] - '0' == first) {
                res += solve(ind + 1 , size + 1 , first , second , s);
                res %= mod;
            }
        }
        
        return dp[ind][size][first][second] = res;
    }
    
    int countPalindromes(string s) {
        for(int i = 0; i < 10001; i++) {
            for(int j = 0; j < 6; j++) {
                for(int k = 0; k < 11; k++) {
                    for(int l = 0; l < 11; l++) {
                        dp[i][j][k][l] = -1;
                    }
                }
            }
        }
        
        return solve(0 , 0 , 10 , 10 , s);
    }
};