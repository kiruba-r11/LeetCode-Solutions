class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) total += nums[i];
        
        int i = 0 , j = 0;
        int sum = 0;
        int ans = -1;
        
        if(total == x) return n;
        
        while(j < n) {
            sum += nums[j];
            while(i < j && (total - sum) < x) {
                sum -= nums[i];
                i++;
            }
            if((total - sum) == x) ans = max(ans , j - i + 1);
            j++;
        }
        
        return ans == -1 ? -1 : n - ans;
    }
};