class Solution {
public:
    int numberOfArrays(vector<int>& nums, int low, int high) {
        long long minval = 0 , maxval = 0;
        int n = nums.size();
        long long prefix = 0;
        
        for(int i = 0; i < n; i++) {
            minval = min(minval , prefix + nums[i]);
            maxval = max(maxval , prefix + nums[i]);
            prefix = prefix + nums[i];
        }
        
        low = low - minval;
        high = high - maxval;
        
        return high < low ? 0 : high - low + 1;
    }
};