class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector <int> ans(n);
        
        // nearest smaller element towards right -> nsr
        stack <int> s;
        
        for(int i = n - 1; i >= 0; i--) {
            while(!s.empty() && s.top() > prices[i]) {
                s.pop();
            }
            ans[i] = prices[i];
            if(!s.empty()) ans[i] -= s.top();
            s.push(prices[i]);
        }
        
        return ans; 
    }
};