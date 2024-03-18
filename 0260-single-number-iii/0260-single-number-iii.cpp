class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        int _xor = 0;
        
        for(int i = 0; i < n; i++) {
            _xor ^= nums[i];
        }
        
        int lastone = 0;
        while(_xor) {
            int rem = _xor % 2;
            if(rem) break;
            _xor /= 2;
            lastone++;
        }
        
        int num1 = 0 , num2 = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] & (1 << lastone)) num1 ^= nums[i];
            else num2 ^= nums[i];
        }
        
        return {num1 , num2};
    }
};