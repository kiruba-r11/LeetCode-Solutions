class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        vector <int> bits(31);
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 31; j++) {
                if(nums[i] & (1 << j)) {
                    bits[j]++;
                }
            }
        }
        
        int mask = 0;
        for(int i = 0; i < 31; i++) {
            if(bits[i] >= k) {
                mask = mask | (1 << i);
            }
        }
        
        return mask;
    }
};