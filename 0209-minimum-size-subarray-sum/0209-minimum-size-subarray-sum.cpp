class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0 , j = 0;
        int sum = 0;
        int ans = n + 1;
        
        while(j < n) {
            sum += nums[j];
            while(sum >= target) {
                if(sum - nums[i] < target) break;
                sum -= nums[i];
                i++;
            }
            if(sum >= target) ans = min(ans , j - i + 1);
            j++;
        }
        
        return ans == n + 1 ? 0 : ans;
    }
};