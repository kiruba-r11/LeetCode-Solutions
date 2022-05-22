class Solution {
public:
    int minimumLines(vector<vector<int>>& nums) {
        int n = nums.size();
        
        if(n <= 2) return n - 1;
        
        sort(nums.begin() , nums.end());
        long double slope = (long double)(nums[1][1] - nums[0][1]) / (nums[1][0] - nums[0][0]);
        
        int ans = 1;
        for(int i = 2; i < n; i++) {
            long double newSlope = 
                (long double)(nums[i][1] - nums[i - 1][1]) / (nums[i][0] - nums[i - 1][0]);
            if(newSlope != slope) {
                ans++;
                slope = newSlope;
            }
        }
        
        return ans;
    }
};