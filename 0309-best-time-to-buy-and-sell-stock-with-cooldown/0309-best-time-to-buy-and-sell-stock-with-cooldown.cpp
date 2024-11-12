class Solution {
public:
    int maxProfit(vector<int>& price) {
        int n = price.size();
        vector <int> nnext(2 , 0) , next(2 , 0) , cur(2 , 0);
    
        for(int i = n - 1; i >= 0; i--) {
            for(int buy = 0; buy <= 1; buy++) {
            
                int ans = 0;
                if(buy == 1) {
                    int buynow = -1 * price[i] + next[0];
                    int buylater = next[1];

                    ans = max(buynow , buylater);
                } else {
                    int sellnow = price[i] + nnext[1];
                    int selllater = next[0];

                    ans = max(sellnow , selllater);
                }
                
                cur[buy] = ans;
            }
            nnext = next;
            next = cur;
        }
        
        return next[1];
    }
};