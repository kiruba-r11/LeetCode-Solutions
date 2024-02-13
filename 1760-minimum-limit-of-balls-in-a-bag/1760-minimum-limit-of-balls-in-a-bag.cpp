class Solution {
public:
    bool possible(vector <int> &nums , int op , int limit) {
        
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] <= limit) continue;
            else {
                int reqop = nums[i] / limit + (nums[i] % limit != 0) - 1;
                if(reqop <= op) {
                    op -= reqop;
                } else {
                    return false;
                }
            }
        }    
        
        return true;
    }
    
    int minimumSize(vector<int>& nums, int op) {
        int low = 1 , high = 1e9;
        int ans = high;
        int mid;
        while(low <= high) {
            mid = low + (high - low) / 2;
            if(possible(nums , op , mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};