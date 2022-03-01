class Solution {
public:
    
    int solve(vector <int> &cost , int index , vector <int> &dp) {
        
        if(index >= cost.size()) return 0;
        
        if(dp[index] != -1) return dp[index];
        
        int climbOne = cost[index] + solve(cost , index + 1 , dp);
        int climbTwo = cost[index] + solve(cost , index + 2 , dp);
        
        return dp[index] = min(climbOne , climbTwo);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        /*
        
        Memoization:
            O(N) time and O(N + N) space complexity
        
        */
        
        int n = cost.size();
        vector <int> dp(n , -1);
            
        int startZero = solve(cost , 0 , dp);
        int startOne = solve(cost , 1 , dp);
              
        return min(startZero , startOne);
    }
};