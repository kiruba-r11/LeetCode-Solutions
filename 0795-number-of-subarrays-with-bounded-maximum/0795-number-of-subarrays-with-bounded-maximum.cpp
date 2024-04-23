class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n = nums.size();
        int prev_invalid = -1;
        int ans = 0;
        int prev_valid_cnt = 0;
        int prev_valid = -1;
        
        for(int i = 0; i < n; i++) {
            if(nums[i] > right) prev_invalid = i;
            else if(nums[i] < left) {
                if(prev_valid > prev_invalid) ans += prev_valid_cnt;
            }
            else {
                prev_valid = i;
                prev_valid_cnt = i - prev_invalid;
                ans += i - prev_invalid;
            }
        }
        
        return ans;
    }
};