class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int i = 0 , j = 0 , sum = 0 , ans = -1 , tsum = 0;
        
        for(int k = 0; k < n; k++) tsum += nums[k];
        
        if(tsum < x) return -1;
        
        while(j < n) {
            int cur = nums[j];
            if((cur + sum) <= (tsum - x)) {
                sum += cur;
                if(sum == (tsum - x)) ans = max(ans , j - i + 1);
                j++;
            } else {
                while((cur + sum) > (tsum - x)) {
                    sum -= nums[i];
                    i++;
                }
            }
        }
        
        if(ans == -1) return -1;
        return n - ans;
    }
};