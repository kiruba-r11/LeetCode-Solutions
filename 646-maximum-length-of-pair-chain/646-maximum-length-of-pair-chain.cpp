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
        vector <int> next(n + 1) , cur(n + 1);
        
        for(int i = n; i >= 1; i--) {
            for(int j = 0; j <= i; j++) {
                int pick = 0 , notPick = 0;
                
                notPick = next[j];
                if(j == 0 || pairs[j - 1][1] < pairs[i - 1][0]) pick = 1 + next[i];
                
                cur[j] = max(pick , notPick);
            }
            next = cur;
        }
        
        return next[0];
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin() , pairs.end());
        
        return solve(pairs);
    }
};