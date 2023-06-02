class Solution {
public:
    int maxSatisfied(vector<int>& nums, vector<int>& temp, int k) {
        int n = nums.size();
        vector <int> prefix(n) , suffix(n);
        
        prefix[0] = temp[0] == 0 ? nums[0] : 0;
        for(int i = 1; i < n; i++) prefix[i] = prefix[i - 1] + (temp[i] == 0 ? nums[i] : 0);
        
        suffix[n - 1] = temp[n - 1] == 0 ? nums[n - 1] : 0;
        for(int i = n - 2; i >= 0; i--) suffix[i] = suffix[i + 1] + (temp[i] == 0 ? nums[i] : 0);
        
        int i = 0 , j = 0 , sum = 0 , ans = 0;
        while(j < n) {
            int window = j - i + 1;
            if(window <= k) {
                sum += nums[j];
                
                if(window == k) {
                    ans = max(ans , sum + 
                             (prefix[i] - (temp[i] == 0 ? nums[i] : 0)) + 
                             (suffix[j] - (temp[j] == 0 ? nums[j] : 0)));
                }
                
                j++;
            } else {
                sum -= nums[i];
                i++;
            }
        }
        
        return ans;
    }
};