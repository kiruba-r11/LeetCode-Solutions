class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        
        int n = nums.size();
        vector <int> suffix(n);
        suffix[n - 1] = nums[n - 1];
        
        for(int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + nums[i];
        }
        
        int prefix = 0;
        vector <int> ans(n);
        for(int i = 0; i < n - 1; i++) {
            ans[i] = abs(prefix - suffix[i + 1]);
            prefix += nums[i];
        }
        
        ans[n - 1] = prefix;
        
        return ans;
        
    }
};