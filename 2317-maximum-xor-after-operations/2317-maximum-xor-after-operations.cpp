class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int n = nums.size();
        int mask = 0;
        
        for(int i = 0; i < 31; i++) {
            int cnt = 0;
            for(int j = 0; j < n; j++) {
                if(nums[j] & (1 << i)) {
                    cnt++;
                }
            }
            if(cnt & 1) mask = mask | (1 << i);
            if(cnt != 0) mask = mask | (1 << i);
        }
        
        return mask;
    }
};