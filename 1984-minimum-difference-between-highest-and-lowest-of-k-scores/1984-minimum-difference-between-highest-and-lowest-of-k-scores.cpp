class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        
        int n = nums.size() , i = 0 , j = 0 , ans = nums[n - 1];
        int cur_min = nums[0] , cur_max = nums[0];
        
        // The min difference between max and min element of k-sized array can be found by sliding the given array using a window of size k.
        
        while(j < n) {
            int window = j - i + 1;
            
            if(window <= k) {
                if(window == k) {
                    
                    // Since array is sorted, the max element of the window will be the last element of the window
                    cur_max = nums[j];
                    
                    // Calculating the ans because the window size is k
                    ans = min(ans , cur_max - cur_min);
                }
                j++;
            } else {
                i++;
                
                // Updating the cur_min, as window is slided by 1 position
                cur_min = nums[i];
            }
        }
        
        return ans;
    }
};