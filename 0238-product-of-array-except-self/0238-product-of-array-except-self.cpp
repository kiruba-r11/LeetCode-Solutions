class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Multiple Approaches:
        // O(N) time and O(N) space -> using prefix and suffix array (no division)
        // O(N) time and O(1) space (two pass) -> using prefix and suffix variable in ans array (no division)
        // O(N) time and O(1) space (one pass) -> combine above approach in single loop (no division)
        
        int n = nums.size();
        vector <int> ans(n , 1);
        
        int pre = 1;
        int suf = 1;
        
        for(int i = 0; i < n; i++) {
            ans[i] = ans[i] * pre;
            pre = pre * nums[i];
            ans[n - i - 1] = ans[n - i - 1] * suf;
            suf = suf * nums[n - i - 1];
        }
        
        return ans;
    }
};