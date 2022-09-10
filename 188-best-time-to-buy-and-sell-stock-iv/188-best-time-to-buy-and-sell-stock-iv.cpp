class Solution {
public:
    int solve(vector <int> &prices , int index , bool canBuy , int k , vector <vector <vector <int>>> &dp) {
    
        if(k == 0 || index == prices.size()) return 0;
        
        int ans = -1e5;
        
        if(dp[index][k][canBuy] != -1) return dp[index][k][canBuy];
        
        // Can I buy this stock?
        if(canBuy) {
            // buy this stock
            int buy = -prices[index] + solve(prices , index + 1 , false , k , dp);
            
            // dont buy this stock
            int dontBuy = solve(prices , index + 1 , true , k , dp);
            
            ans = max(buy , dontBuy);
        } else {
            
            // sell this stock
            int sell = prices[index] + solve(prices , index + 1 , true , k - 1 , dp);
            
            // dont sell this stock
            int dontSell = solve(prices , index + 1 , false , k , dp);
            
            ans = max(sell , dontSell);
        }
        
        return dp[index][k][canBuy] = ans;
    }
    
    int solve(vector <int> &prices , int k) {
        
        int n = prices.size();
        if(n == 0) return 0;
        
        vector <vector <int>> cur(k + 1 , vector <int> (2)) , next(k + 1 , vector <int> (2));
        
        for(int i = n - 1; i >= 0; i--) {
            for(int j = 0; j <= k; j++) {
                for(int m = 0; m <= 1; m++) {
                    int ans = -1e5;
                    if(m == 1) {
                        int buy = -prices[i] + ((j == 0) ? 0 : next[j][0]);
                        int dontBuy = next[j][1];
                        ans = max(buy , dontBuy);
                    } else {
                        int sell = prices[i] + ((j == 0) ? 0 : next[j - 1][1]);
                        int dontSell = next[j][0];
                        ans = max(sell , dontSell);
                    }
                    
                    cur[j][m] = ans;
                }
            }
            next = cur;
        }
        
        return next[k][1];
    }
    
    int maxProfit(int k, vector<int>& prices) {
        // int n = prices.size();
        // vector <vector <vector <int>>> dp(n , vector <vector <int>> (k + 1 , vector <int> (2 , -1)));
        // return solve(prices , 0 , true , k , dp);
        
        return solve(prices , k);
    }
};