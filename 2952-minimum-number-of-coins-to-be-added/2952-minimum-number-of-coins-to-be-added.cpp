class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        
        /*
        
        Intuition:
            1. Pattern -> 
                [1] = [1]
                [1 , 2] = [1 , 2 , 3]
                [1 , 2 , 4] = [1 , 2 , 3 , 4 , 5 , 6 , 7]        
                
            If numbers [2 ^ 0 , 2 ^ 1 , ... , 2 ^ n] are present, then their sum of subsequences can form 
            [1 , 2 , ... , 2 ^ (n + 1) - 1]
            
            2. If we have an array whose sum of subsequences form [1 , 2 , ... , k], and we have used all the numbers of the
            array, then we can add (k + 1) to increase the range to [1 , 2 , ... , k , ... , 2 * k + 1].
            
            3. If we have not used all the numbers, then every number m, will increase the range to [1 , m + k]
        
        */
        
        
        sort(coins.begin() , coins.end());
        int n = coins.size();
        int ans = 0;
        int range = 0;
        for(int i = 0; i < n; i++) {
            if(range < target) {
                while(i < n && coins[i] > range) {
                    if(range + 1 != coins[i]) {
                        ans++;
                    } else {
                        i++;
                    }
                    range = range * 2 + 1;
                } 
                if(i < n) range += coins[i];   
            }
        }
        
        while(range < target) {
            range = range * 2 + 1;
            ans++;
        }
        
        return ans;
        
    }
};
