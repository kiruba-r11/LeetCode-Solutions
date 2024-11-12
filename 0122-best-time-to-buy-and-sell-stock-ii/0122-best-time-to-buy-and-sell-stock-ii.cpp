class Solution {
public:
    int solve(vector <int> &price , int buy , int i) {
        
        int n = price.size();
        if(i == n) return 0;
            
        int ans = 0;
        
        if(buy == 1) {
            int buynow = -1 * price[i] + solve(price , 0 , i + 1);
            int buylater = solve(price , 1 , i + 1);
            
            ans = max(buynow , buylater);
        } else {
            int sellnow = price[i] + solve(price , 1 , i + 1);
            int selllater = solve(price , 0 , i + 1);
            
            ans = max(sellnow , selllater);
        }
        
        return ans;
    }
    
    int maxProfit(vector<int>& price) {
        
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
                    int sellnow = price[i] + next[1];;
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