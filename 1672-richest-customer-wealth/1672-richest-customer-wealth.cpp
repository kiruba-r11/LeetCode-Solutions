class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        
        /*
        
        O(N * M) time and O(1) space
        Idea -> Basic Arithmetic
        
        */
        
        int cur_wealth = 0 , max_wealth = 0 , n = accounts.size() , m = accounts[0].size();
        
        for(int i = 0; i < n; i++) {
            
            // Initialising the current wealth to calculate it for every new customer
            cur_wealth = 0;
            
            for(int j = 0; j < m; j++) {
                
                // Adding all the wealth a customer has in all his bank accounts
                cur_wealth += accounts[i][j];
            }
            
            // Updating the max wealth 
            max_wealth = max(max_wealth , cur_wealth);
        }
        
        return max_wealth;
    }
};