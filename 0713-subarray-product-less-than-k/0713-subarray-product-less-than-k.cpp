class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0 , j = 0;
        int prd = 1;
        int ans = 0;
        
        if(k == 0) return ans;
        
        while(j < n) {
            prd = prd * nums[j];
            while(i < j && prd >= k) {
                prd /= nums[i];
                i++;
            }
            if(prd < k) ans += j - i + 1;
            j++;
        }
        
        return ans;
    }
};