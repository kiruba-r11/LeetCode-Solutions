class Solution {
public:
    int maxSatisfied(vector<int>& nums, vector<int>& temp, int k) {
        int n = nums.size();
        int sum = 0 , ans = 0;
        
        for(int i = 0; i < n; i++) sum += (temp[i] == 0 ? nums[i] : 0);
        
        int i = 0 , j = 0 , cursum = 0;
        while(j < n) {
            int window = j - i + 1;
            if(window <= k) {
                if(temp[j] == 1) cursum += nums[j];
                
                if(window == k) {
                    ans = max(ans , sum + cursum);
                }
                
                j++;
            } else {
                if(temp[i] == 1) cursum -= nums[i];
                i++;
            }
        }
        
        return ans;
    }
};