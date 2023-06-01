class Solution {
public:
    int maxScore(vector<int>& nums, int len) {
        int n = nums.size();
        int k = n - len;
        int i = 0 , j = 0 , sum = 0 , ans = INT_MAX , res = 0;
        
        for(int i = 0; i < n; i++) res += nums[i];
        
        while(j < n) {
            int window = j - i + 1;
            if(window <= k) {
                sum += nums[j];
                if(window == k) {
                    ans = min(ans , sum);
                }
                j++;
            } else {
                sum -= nums[i];
                i++;
            }
        }
        
        return res - ans;
    }
};