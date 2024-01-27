class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        int start = nums[0][0];
        int end = nums[0][1];
        int ans = 0;
        
        for(int i = 1; i < n; i++) {
            if(nums[i][0] <= end) {
                end = max(end , nums[i][1]);
            } else {
                ans += end - start + 1;
                start = nums[i][0];
                end = nums[i][1];
            }
        }
        
        ans += end - start + 1;
        return ans;
    }
};