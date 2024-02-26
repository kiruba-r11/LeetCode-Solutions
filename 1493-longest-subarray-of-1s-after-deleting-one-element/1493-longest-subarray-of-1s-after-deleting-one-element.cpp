class Solution {
public:
    bool condition(vector <int> &nums , int k) {
    
        int i = 0 , j = 0 , n = nums.size();
        int ones = 0;
        int flips = 0;
        
        while(j < n) {
            int window = j - i + 1;
            if(window <= k) {
                if(nums[j] == 1) ones++;
                else flips++;
                
                if(window == k) {
                    if(flips <= 1) return true;
                }
                
                j++;
            } else {
                if(nums[i] == 1) ones--;
                else flips--;
                i++;
            }
        }
        
        return false;
    }
    
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int low = 0 , high = n;
        int ans = 0;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(condition(nums , mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans - 1;
    }
};