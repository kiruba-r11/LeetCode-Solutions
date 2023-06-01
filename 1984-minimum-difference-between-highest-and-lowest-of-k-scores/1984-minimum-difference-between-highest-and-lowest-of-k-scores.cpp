class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        int i = 0 , j = 0 , n = nums.size();
        int high = -1 , low = -1;
        int ans = INT_MAX;
        
        while(j < n) {
            int window = j - i + 1;
            if(window <= k) {
                if(window == k) {
                    high = nums[j];
                    low = nums[i];
                    ans = min(ans , abs(high - low));
                }
                j++;
            } else {
                i++;
            }
        }
        
        return ans;
    }
};