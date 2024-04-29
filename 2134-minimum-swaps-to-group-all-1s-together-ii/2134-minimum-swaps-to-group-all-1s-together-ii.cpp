class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int i = 0 , j = 0;
        int n = nums.size();
        int ans = n + 1;
        int ones = 0 , cnt = 0;
        for(int i = 0; i < n; i++) ones += nums[i];
        
        while(j < 2 * n) {
            int window = j - i + 1;
            if(window <= ones) {
                cnt += nums[j % n];
                if(window == ones) ans = min(ans , ones - cnt);
                j++;
            } else {
                cnt -= nums[i % n];
                i++;
            }
        }
        
        return ans;
    }
};