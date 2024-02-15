class Solution {
public:
    bool condition(vector <int> &nums , int target , int k) {    
        
        int n = nums.size();
        int i = 0 , j = 0;
        int sum = 0;
        
        while(j < n) {
            int window = j - i + 1;
            if(window <= k) {
                sum += nums[j];
                
                if(window == k) {
                    if(sum >= target) return true;
                }
                
                j++;
            } else {
                sum -= nums[i];
                i++;
            }
        }
        
        return false;
    }
    
    int minSubArrayLen(int target, vector<int>& nums) {
        int low = 0 , high = nums.size();
        int ans = 0;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(condition(nums , target , mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};