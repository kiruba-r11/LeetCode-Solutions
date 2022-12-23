class Solution {
public:
    int solve(vector <int> &prices , int index , bool canBuy , vector <vector <int>> &dp) {
        
        if(index >= prices.size()) return 0;
        
        if(dp[index][canBuy] != -1) return dp[index][canBuy];
        
        int ans = -1e5;
        
        // Can I buy this stock?
        if(canBuy) {
            // buy this stock
            int buy = -prices[index] + solve(prices , index + 1 , false , dp);
            
            // dont buy this stock
            int dontBuy = solve(prices , index + 1 , true , dp);
            
            ans = max(buy , dontBuy);
        } else {
            // sell this stock
            int sell = prices[index] + solve(prices , index + 2 , true , dp);
            
            // dont sell this stock
            int dontSell = solve(prices , index + 1 , false , dp);
            
            ans = max(sell , dontSell);
        }
        
        return dp[index][canBuy] = ans;
    }
    
    int solve(vector <int> &prices) {
        
        int n = prices.size();
        vector <int> next(2) , cur(2);
        
        for(int i = n - 1; i >= 0; i--) {
            for(int j = 0; j <= 1; j++) {
                int ans = -1e5;
                
                if(j == 1) {
                    int buy = -prices[i] + next[0];
                    int dontBuy = next[1];
                    
                    ans = max(buy , dontBuy);
                } else {
                    int sell = prices[i] + next[1];
                    int dontSell = next[0];
                    
                    ans = max(sell , dontSell);
                }
                
                cur[j] = ans;
            }
            next = cur;
        }
        
        return next[1];
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector <vector <int>> dp(n , vector <int> (2 , -1));
        return solve(prices , 0 , true , dp);
    }
};