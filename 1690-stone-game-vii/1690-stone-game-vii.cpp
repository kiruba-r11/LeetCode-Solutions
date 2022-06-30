class Solution {
public:
    int dp[1001][1001][2];
    
    int getSum(vector <int> &stones , int start , int end , vector <int> &prefix) {
        
        int n = stones.size();
        int sum = 0;
        
        // for(int i = start; i <= end; i++) sum += stones[i];
        if(start < n && end >= 0) sum = prefix[end] - prefix[start] + stones[start];
        
        return sum;
    }
    
    int solve(vector <int> &stones , int start , int end , int alice , vector <int> &prefix) {
        
        if(start > end) return 0;
        
        if(dp[start][end][alice] != -1) return dp[start][end][alice];
        
        if(alice) {
            int a = solve(stones , start + 1 , end , 0 , prefix) + getSum(stones , start + 1 , end , prefix);
            int b = solve(stones , start , end - 1 , 0 , prefix) + getSum(stones , start , end - 1 , prefix);
            return dp[start][end][alice] = max(a , b);
        } 
        
        int a = solve(stones , start + 1 , end , 1 , prefix) - getSum(stones , start + 1 , end , prefix);
        int b = solve(stones , start , end - 1 , 1 , prefix) - getSum(stones , start , end - 1 , prefix);
        
        return dp[start][end][alice] = min(a , b);
    }
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        
        vector <int> prefix(n);
        prefix[0] = stones[0];
        
        for(int i = 1; i < n; i++) prefix[i] = prefix[i - 1] + stones[i];
        
        for(int i = 0; i < 1000; i++) {
            for(int j = 0; j < 1000; j++) {
                for(int k = 0; k < 2; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }
        
        return solve(stones , 0 , n - 1 , 1 , prefix);
    }
};