class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector <int> ans(n);
        
        int _xor = 0;
        for(int i = 0; i < n; i++) _xor = _xor ^ nums[i];
        
        for(int i = 0; i < n; i++) {
            int k = 0;
            for(int bit = 0; bit <= 20; bit++) {
                if(!(_xor & (1 << bit))) {
                    if((k + (1 << bit)) < (1 << maximumBit)) {
                        k += (1 << bit);
                    } else {
                        break;
                    }
                }
            }
            ans[i] = k;
            _xor = _xor ^ nums[n - i - 1];
        }
        
        return ans;
    }
};
