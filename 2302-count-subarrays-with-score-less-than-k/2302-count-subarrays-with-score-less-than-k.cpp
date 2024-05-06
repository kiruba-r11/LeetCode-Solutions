class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        int i = 0 , j = 0;
        long long sum = 0;
        int len = 0;
        long long ans = 0;
        
        while(j < n) {
            sum += nums[j];
            len = j - i + 1;
            while(sum * 1LL * len >= k) {
                sum -= nums[i];
                i++;
                len = j - i + 1;
            }
            if(sum * len < k) ans += j - i + 1;
            j++;
        }
        
        return ans;
    }
};