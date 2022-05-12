class Solution {
public:
    int solve(vector <vector <int>> &pairs , int index , int select , vector <vector <int>> &dp) {
 
        if(index == pairs.size()) return 0;
        
        if(dp[index][select + 1] != -1) return dp[index][select + 1];
        
        int pick = 0 , notPick = 0;
        
        notPick = solve(pairs , index + 1 , select , dp);

        if(select == -1 || pairs[select][1] < pairs[index][0]) 
            pick = 1 + solve(pairs , index + 1 , index , dp);
        
        return dp[index][select + 1] = max(pick , notPick);
        
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin() , pairs.end());
        
        int n = pairs.size() , m = pairs.size();
        
        vector <vector <int>> dp(n , vector <int> (m + 1 , -1));
        return solve(pairs , 0 , -1 , dp);
    }
};