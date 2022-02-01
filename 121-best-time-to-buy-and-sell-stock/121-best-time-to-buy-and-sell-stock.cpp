class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size() , ans = 0 , curmax = prices[n - 1];
        
        for(int i = n - 2; i >= 0; i--) {
            
            ans = max(ans , curmax - prices[i]);
            curmax = max(curmax , prices[i]);
        }
        
        return ans;
    }
};