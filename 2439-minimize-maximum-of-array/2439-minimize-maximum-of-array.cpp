class Solution {
public:
    bool condition(vector <int> nums , int val) {
    
        int n = nums.size();
        if(nums[0] > val) return false;
        long long free = val - nums[0];
        
        for(int i = 1; i < n; i++) {    
            if(nums[i] > val) {
                if(free < nums[i] - val) return false;
                free -= nums[i] - val;
            } else {
                free += val - nums[i];
            }
        }
        
        return true;
    }
    
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        int low = 0 , high = nums[0];
        
        for(int i = 0; i < n; i++) high = max(high , nums[i]);
        int ans = high;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(condition(nums , mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};