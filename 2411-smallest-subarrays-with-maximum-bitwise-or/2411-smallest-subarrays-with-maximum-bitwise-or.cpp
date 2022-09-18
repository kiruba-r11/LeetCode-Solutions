class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        
        int n = nums.size();
        vector <int> store(30 , 0);
        vector <int> ans(n);
        
        for(int i = n - 1; i >= 0; i--) {
            
            int idx = -1;
            for(int bit = 0; bit < 30; bit++) {
                if((1 << bit) & nums[i]) {
                    store[bit] = i;
                }
                idx = max(idx , store[bit]);
            }
            
            ans[i] = (idx - i + 1) <= 0 ? 1 : (idx - i + 1);
        }
        
        return ans;
    }
};