class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        
        // When nums[i] = -1 (for nums[i] < k), 
        //  and nums[i] = 1 (for nums[i] > k), 
        //  and nums[i] = 0 (for nums[i] == k), then
        
        // For all even length subarray, the sum will be 1
        // For all odd length subarray, the sum will be 0
        
        int mid = -1 , n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] == k) {
                mid = i;
                nums[i] = 0;
            } else if(nums[i] < k) {
                nums[i] = -1;
            } else {
                nums[i] = 1;
            }
        }
        
        // Because nums[mid] is itself a subarray with length 1 and median = k
        int ans = 1;
        
        int sum = 0;
        map <int , int> cnt_left; // for prefix hashing
        
        // Subarrays ending with k
        for(int i = mid - 1; i >= 0; i--) {
            sum += nums[i];
            
            if(sum == 0 || sum == 1) ans++;
            
            cnt_left[sum]++;
        }
        
        sum = 0;
        
        // Subarrays starting with k
        for(int i = mid + 1; i < n; i++) {
            sum += nums[i];
            
            if(sum == 0 || sum == 1) ans++;
            
            // Subarrays with k not in starting or ending positions
            
            // To form a sum = 0
            ans += cnt_left[-sum];
            
            // To form a sum = 1
            ans += cnt_left[1 - sum];
        }
        
        return ans;
    }
};