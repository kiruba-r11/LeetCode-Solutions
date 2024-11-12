class Solution {
public:
    int maxProfit(vector<int>& price, int fee) {
        int n = price.size();
        vector <int> next(2 , 0) , cur(2 , 0);
        
        for(int i = n - 1; i >= 0; i--) {
            for(int buy = 0; buy <= 1; buy++) {
            
                int ans = 0;
                if(buy == 1) {
                    int buynow = -1 * price[i] + next[0];
                    int buylater = next[1];

                    ans = max(buynow , buylater);
                } else {
                    int sellnow = price[i] + next[1] - fee;
                    int selllater = next[0];

                    ans = max(sellnow , selllater);
                }
                
                cur[buy] = ans;
            }
            next = cur;
        }
        
        return next[1];
    }
};