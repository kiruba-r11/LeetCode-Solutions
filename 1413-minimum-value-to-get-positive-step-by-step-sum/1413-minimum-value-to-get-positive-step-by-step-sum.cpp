class Solution {
public:
    bool helper(vector <int> &nums , int start) {
    
        int n = nums.size();
        int prefix = start;
        for(int i = 0; i < n; i++) {
            prefix = nums[i] + prefix;
            if(prefix < 1) return false;
        }
        
        return true;
    }
    
    int minStartValue(vector<int>& nums) {
        int low = 0 , high = 10001;
        int ans = 0;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(helper(nums , mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans == 0 ? 1 : ans;
    }
};