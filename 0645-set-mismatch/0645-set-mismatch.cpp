class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int _xor = 0;
        int n = nums.size();
        
        for(int i = 1; i <= n; i++) {
            _xor ^= i;
        }
        
        for(int i = 0; i < n; i++) {
            _xor ^= nums[i];
        }
        
        int last = 0;
        while(true) {
            if(_xor & (1 << last)) break;
            last++;
        }
        
        int num1 = 0 , num2 = 0;
        
        for(int i = 1; i <= n; i++) {
            if(i & (1 << last)) {
                num1 ^= i;
            } else {
                num2 ^= i;
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(nums[i] & (1 << last)) {
                num1 ^= nums[i];
            } else {
                num2 ^= nums[i];
            }
        }
        
        bool check = false;
        for(int i = 0; i < n; i++) {
            if(num1 == nums[i]) {
                check = true;
                break;
            }
        }
        
        if(check) return {num1 , num2};
        return {num2 , num1};
    }
};