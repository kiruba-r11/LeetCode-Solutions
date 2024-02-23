class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector <int> ans(n);
        
        int sum = 0;
        for(int i = 0; i < n; i++) sum += nums[i];
        
        int prefix = 0;
        for(int i = 0; i < n; i++) {
            ans[i] = abs(prefix - i * nums[i]) + abs((n - (i + 1)) * nums[i] - (sum - prefix - nums[i]));
            prefix += nums[i];
        }   
        
        return ans;
    }
};