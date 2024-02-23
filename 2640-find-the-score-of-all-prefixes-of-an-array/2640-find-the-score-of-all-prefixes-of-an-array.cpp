class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        int prefix = 0;
        long long sum = 0;
        
        vector <long long> ans(n);    
        
        for(int i = 0; i < n; i++) {
            prefix = max(prefix , nums[i]);
            long long conver = nums[i] + prefix;
            sum += conver;
            ans[i] = sum;
        }
        
        return ans;
    }
};