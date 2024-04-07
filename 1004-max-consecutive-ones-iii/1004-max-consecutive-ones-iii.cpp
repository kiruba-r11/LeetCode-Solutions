class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0 , j = 0 , ans = 0 , flips = 0;
        int n = nums.size();
        while(j < n) {
            if(nums[j] == 0) flips++;
            while(flips > k) {
                if(nums[i] == 0) flips--;
                i++;
            }
            if(flips <= k) ans = max(ans , j - i + 1);
            j++;
        }
        
        return ans;
    }
};