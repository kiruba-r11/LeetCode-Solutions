class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        
        int n = nums.size(); 
        int i = 0 , j = 0;
        long long sum = 0;
        int ans = 0;
        
        while(j < n) {
            sum += nums[j];
            long long increase = sum - nums[j]; // exclude jth element
            long long cnt = j - i; // exclude jth element
            while(increase + k < cnt * 1LL * nums[j]) {
                sum -= nums[i];
                i++;
                increase = sum - nums[j];
                cnt = j - i;
            }
            
            if(increase + k >= cnt * nums[j]) ans = max(ans , j - i + 1);
            j++;
        }
        
        return ans;
    }
};
