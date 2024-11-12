class Solution {
public:
    int maxProfit(int K, vector<int>& price) {
        int n = price.size();
        vector <vector <int>> next(K + 2 , vector <int> (2 , 0)) , cur(K + 2 , vector <int> (2 , 0));
    
        for(int i = n - 1; i >= 0; i--) {
            for(int k = K; k >= 0; k--) {
                for(int buy = 0; buy <= 1; buy++) {
                    int ans = 0;
                    if(buy == 1) {
                        int buynow = -1 * price[i] + next[k][0];
                        int buylater = next[k][1];

                        ans = max(buynow , buylater);
                    } else {
                        int sellnow = price[i] + next[k + 1][1];
                        int selllater = next[k][0];

                        ans = max(sellnow , selllater);
                    }

                    cur[k][buy] = ans;   
                }
            }
            next = cur;
        }
        
        return next[1][1];
    }
};