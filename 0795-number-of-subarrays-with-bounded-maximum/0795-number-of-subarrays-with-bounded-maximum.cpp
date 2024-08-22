class Solution {
public:
    int solve(vector <int> &nums , int range) {
        int n = nums.size();
        int prefix_cnt = 0;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] <= range) {
                prefix_cnt++;
            } else {
                prefix_cnt = 0;
            }
            ans += prefix_cnt;
        }
        
        return ans;
    }
    
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int l = solve(nums , left - 1);
        int r = solve(nums , right);
        
        return r - l;
    }
};