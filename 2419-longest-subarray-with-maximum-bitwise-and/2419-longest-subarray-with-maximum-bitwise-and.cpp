class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxe = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            maxe = max(maxe , nums[i]);
        }
        
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            int j = i + 1;
            while(j < n && nums[i] == nums[j]) j++;
            
            if(nums[i] == maxe) cnt = max(cnt , j - i);
            i = j - 1;
        }
        return cnt;
    }
};