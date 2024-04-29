class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int i = 0 , j = 0;
        set <pair <int , int>> s;
        int ans = 0;
        int minval , maxval;
        
        while(j < n) {
            s.insert({nums[j] , j});
            minval = s.begin()->first;
            maxval = s.rbegin()->first;
            while(i < j && maxval - minval > limit) {
                if(s.count({nums[i] , i}) == 1) s.erase({nums[i] , i});
                minval = s.begin()->first;
                maxval = s.rbegin()->first;
                i++;
            }
            if(maxval - minval <= limit) ans = max(ans , j - i + 1);
            j++;
        }
        
        return ans;
    }
};