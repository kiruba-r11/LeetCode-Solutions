class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        /*
        
        O(N) time and O(1) space complexity
        Idea -> Kadane's Algorithm
        
            At every index, decide whether to
                1. Start a new subarray
                2. Continue with the previous subarray
                
            The subarray with maxsum of the above step, is the new subarray with us.
            Now, this new subarray can or cannot contribute to our overall result. Have a check on that.
        
        */
        
        int n = nums.size();
        int curMax = nums[0] , finalMax = nums[0];
        
        for(int i = 1; i < n; i++) {
            curMax = max(curMax + nums[i] , nums[i]);
            finalMax = max(finalMax , curMax);
        }
        
        return finalMax;
    }
};