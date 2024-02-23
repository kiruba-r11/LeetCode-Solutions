class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        int i = 0 , j = 0;
        int cursum = 0;
        int ans = 0;
        
        for(int i = 0; i < n; i++) sum += nums[i];
        
        while(j < n) {
            int window = j - i + 1;
            if(window <= (n - k)) {
                cursum += nums[j];
                if(window == (n - k)) {
                    ans = max(ans , sum - cursum);
                }
                j++;
            } else {
                cursum -= nums[i];
                i++;
            }
        }
        
        return ans;
    }
};