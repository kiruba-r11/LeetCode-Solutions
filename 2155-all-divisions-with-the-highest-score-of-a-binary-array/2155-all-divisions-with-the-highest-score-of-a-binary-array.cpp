class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        
        /*
        
        O(N) time and O(1) space complexity (not including the resultant array)
        Idea -> Prefix Sum 
         
        */
        
        int n = nums.size() , ones = 0 , cur_ones = 0 , cur_zeroes = 0 , maxsum = -1 , cursum = -1;
        vector <int> ans;
        
        for(int i = 0; i < n; i++) {
            
            // To count the no. of ones in the array
            ones += nums[i];
        }
        
        
        for(int i = 0; i <= n; i++) {
            if(i == 0) {
                
                // Total ones
                cursum = ones;
            } else if(i == n) {
                
                // Total zeroes
                cursum = cur_zeroes;
            } else {
                
                // No. of ones from ith to (n - 1)ith is (total ones in the array - no. of ones from 0th to (i - 1)th)
                cursum = cur_zeroes + abs(ones - cur_ones);
            }
            
            if(cursum >= maxsum) {  
                
                // If new max is found, empty the array
                if(cursum > maxsum) 
                    ans = {};
                ans.push_back(i);
            }
            
            // Count ones from 0 to ith index
            if(i < n && nums[i] == 1) cur_ones++;
            
            // Count zeroes from 0 to ith index
            if(i < n && nums[i] == 0) cur_zeroes++;
            
            maxsum = max(maxsum , cursum);
        }
        
        return ans;
    }
};