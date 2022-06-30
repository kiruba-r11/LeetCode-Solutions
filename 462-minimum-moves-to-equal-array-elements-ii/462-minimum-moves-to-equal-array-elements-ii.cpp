class Solution {
public:
    int minMoves2(vector<int>& nums) {
       
        int n = nums.size();
        int ans = 0 , mid = 0;
        
        sort(nums.begin() , nums.end());
        
        if(n & 1) mid = nums[n / 2];
        else mid = (nums[n / 2] + nums[n / 2 - 1]) / 2;
    
        for(int i = 0; i < n; i++) ans += abs(nums[i] - mid);
    
        return ans;
    }
};