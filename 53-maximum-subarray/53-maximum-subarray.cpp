class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        /*
        
        O(N) time and O(1) space
        Idea -> Basic logics
        
        */
        
        int cursum = 0 , maxsum = INT_MIN , maxelem = nums[0];
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            cursum += nums[i];
            
            // If cursum is less than 0, taking it will effectively reduce the sum of subarray starting from next point.
            if(cursum < 0) cursum = 0;
            
            maxelem = max(maxelem , nums[i]);
            maxsum = max(maxsum , cursum);
        }
        
        if(maxsum == 0) maxsum = maxelem;
        
        return maxsum;
    }
};