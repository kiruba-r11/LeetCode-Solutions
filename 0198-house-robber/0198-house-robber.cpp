class Solution {
public:
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        int pprev = 0 , prev = nums[0];
        
        for(int i = 1; i < n; i++) {
            
            int pick = pprev + nums[i];
            int dont = prev;
            int cur = max(pick , dont);
            
            pprev = prev;
            prev = cur;
            
        }
        
        return prev;
    }
};