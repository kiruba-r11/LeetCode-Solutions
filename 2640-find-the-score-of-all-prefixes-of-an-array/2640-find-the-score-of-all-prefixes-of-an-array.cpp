class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        int prefix_max = nums[0];
        
        vector <long long> ans(n);
        ans[0] = nums[0] * 2;
        
        for(int i = 1; i < n; i++) {
            prefix_max = max(nums[i] , prefix_max);
            ans[i] = ans[i - 1] + prefix_max + nums[i];
        }
        
        return ans;
    }
};