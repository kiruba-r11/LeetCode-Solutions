class Solution {
public:
    int slide(vector <int> &nums , int goal) {
        // Form subarrays ending at index j
        // Then, count all the valid subarrays from 0 to i
        
        if(goal < 0) return 0;
        
        int i = 0 , j = 0;
        int n = nums.size();
        int sum = 0;
        int ans = 0;
        
        while(j < n) {
            sum += nums[j];
            while(sum > goal) {
                sum -= nums[i];
                i++;
            }
            if(sum <= goal) ans += j - i + 1;
            j++;
        }
        
        return ans;
    }
    
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // To find subarray count with sum == k
        // Find:
        //      s1 = Subarray count with sum <= k
        //      s2 = Subarray count with sum <= k - 1
        // s = s1 - s2
        
        return slide(nums , goal) - slide(nums , goal - 1);
    }
};