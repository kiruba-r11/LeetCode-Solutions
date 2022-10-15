class Solution {
public:
    bool solve(vector <int> &nums , int val) {
        int n = nums.size();
        
        if(nums[0] > val) return false;
        long long extra = val - nums[0];
        int prev = nums[0];
        
        for(int i = 1; i < n; i++) {
            if(nums[i] > val) {
                int ex = nums[i] - val;
                if(ex > extra) return false;
                extra -= ex;
            } else {
                extra += val - nums[i];
            }
            
            prev = nums[i];
        }
        
        return true;
    }
    
    int minimizeArrayValue(vector<int>& nums) {
        int low = 0 , high = *max_element(nums.begin() , nums.end()) , ans = high;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(solve(nums , mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};