class Solution {
public:
    int solve(vector <vector <int>> &pairs , int index , int select , vector <vector <int>> &dp) {
 
        if(index == pairs.size() + 1) return 0;
        
        if(dp[index][select] != -1) return dp[index][select];
        
        int pick = 0 , notPick = 0;
        
        notPick = solve(pairs , index + 1 , select , dp);

        if(select == 0 || pairs[select - 1][1] < pairs[index - 1][0]) 
            pick = 1 + solve(pairs , index + 1 , index , dp);
        
        return dp[index][select] = max(pick , notPick);
        
    }
    
    int solve(vector <vector <int>> &pairs) {
        
        int n = pairs.size();
        
        vector <vector <int>> dp(n + 1 , vector <int> (n + 1));
        
        for(int i = n - 1; i >= 1; i--) {
            for(int j = 0; j <= i; j++) {
                int pick = 0 , notPick = 0;
                
                notPick = dp[i + 1][j];
                if(j == 0 || pairs[j][1] < pairs[i][0]) pick = 1 + dp[i + 1][i];
                
                dp[i][j] = max(pick , notPick);
            }
        }
        
        return dp[0][1];
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin() , pairs.end());
        int n = pairs.size();
        vector <vector <int>> dp(n + 1 , vector <int> (n + 1 , -1));
        return solve(pairs , 1 , 0 , dp);
        // return solve(pairs);
    }
};