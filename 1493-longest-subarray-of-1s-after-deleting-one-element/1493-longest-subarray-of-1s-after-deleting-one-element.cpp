class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int one = 0;
        int i = 0 , j = 0;
        int n = nums.size();
        int ans = 0;
        
        while(j < n) {
            one += nums[j];
            while((j - i + 1) - one > 1) {
                one -= nums[i];
                i++;
            }
            if((j - i + 1) - one <= 1) ans = max(ans , j - i + 1);
            j++;
        }
        
        return ans - 1;
    }
};