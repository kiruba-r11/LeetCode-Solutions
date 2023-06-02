class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0 , j = 0 , sum = 0 , ans = n + 1;
        
        while(j < n) {
            int cur = nums[j];
            if(cur + sum < target) {
                sum += cur;
                j++;
            } else {
                while((cur + sum) >= target) {
                    sum -= nums[i];
                    i++;
                }
                ans = min(ans , j - i + 2);
            }
        }
        
        return ans == (n + 1) ? 0 : ans;
    }
};