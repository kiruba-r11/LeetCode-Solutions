class Solution {
public:
    
    int solve(vector <int> &cost , int index , vector <int> &dp) {
        
        if(index >= cost.size()) return 0;
        
        if(dp[index] != -1) return dp[index];
        
        int climbOne = cost[index] + solve(cost , index + 1 , dp);
        int climbTwo = cost[index] + solve(cost , index + 2 , dp);
        
        return dp[index] = min(climbOne , climbTwo);
    }
    
    int solve(vector <int> &cost) {
        
        int n = cost.size();
        vector <int> dp(n);
        
        for(int i = n - 1; i >= 0; i--) {
            
            int climbOne = cost[i] , climbTwo = cost[i];
            
            if(i + 1 < n) climbOne += dp[i + 1];
            if(i + 2 < n) climbTwo += dp[i + 2];
            
            dp[i] = min(climbOne , climbTwo);
        }
        
        return min(dp[0] , dp[1]);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        /*
        
        Memoization:
            O(N) time and O(N + N) space complexity
            
        Tabulation:
            O(N) time and O(N) space complexity
        
        */
        
//         int n = cost.size();
//         vector <int> dp(n , -1);
            
//         int startZero = solve(cost , 0 , dp);
//         int startOne = solve(cost , 1 , dp);
              
//         return min(startZero , startOne);
        
        return solve(cost);
    }
};