class Solution {
public:
    int find(vector <int> &nums , int range) {
        int n = nums.size();
        int ans = 0;
        int prev_invalid = -1;
        
        for(int i = 0; i < n; i++) {
            if(nums[i] > range) prev_invalid = i;
            else ans += i - prev_invalid;
        }
        
        return ans;
    }
    
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {

        // Better Intuition for problems with [left , right] range
        // Find [right] (<= right)
        // Find [left - 1] (<= left)
        // Find [right] - [left - 1] ([left , right])
        
        int r = find(nums , right);
        int l = find(nums , left - 1);
        
        int ans = r - l;
        
        return ans;
    }
};