class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        /*
        
        O(N) time and O(1) space complexity
        Idea -> Storing the max from right (similar to Leaders of an Array)
        
        */
        
        int n = prices.size() , ans = 0 , curmax = prices[n - 1];
        
        // Finding the max from right, as optimal solution is to sell at the day which has max value, and buy at the day which has min value. Note we must sell after we buy, that's why we traverse from right. (making sure we buy first and sell next). 
        for(int i = n - 2; i >= 0; i--) {
            ans = max(ans , curmax - prices[i]);
            curmax = max(curmax , prices[i]);
        }
        
        return ans;
    }
};