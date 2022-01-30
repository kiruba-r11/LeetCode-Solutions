class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        
        /*
        
        O(N) time and space complexity
        Idea -> Prefix Sum
         
        */
        
        int n = nums.size() , ones = 0 , cur_ones = 0 , maxsum = -1 , cursum = -1;
        vector <int> prefix(n , 0) , ans;
        
        // Prefix array to store the sum of zeroes from 0 to ith index
        for(int i = 0; i < n; i++) {
            
            if(i == 0) prefix[i] = 1 - nums[i];
            else prefix[i] = prefix[i - 1] + (1 - nums[i]);
            
            ones += nums[i];
        }
        
        
        for(int i = 0; i <= n; i++) {
            if(i == 0) {
                
                // Total ones
                cursum = ones;
            } else if(i == n) {
                
                // Total zeroes
                cursum = prefix[n - 1];
            } else {
                
                // No. of ones from ith to (n - 1)ith is (total ones in the array - no. of ones from 0th to (i - 1)th)
                cursum = prefix[i - 1] + abs(ones - cur_ones);
            }
            
            if(cursum >= maxsum) {  
                
                // If new max is found, empty the array
                if(cursum > maxsum) 
                    ans = {};
                ans.push_back(i);
            }
            
            // Count ones from 0 to ith index
            if(i < n && nums[i] == 1) cur_ones++;
            maxsum = max(maxsum , cursum);
        }
        
        return ans;
    }
};