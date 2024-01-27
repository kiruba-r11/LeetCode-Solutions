class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        
        vector <int> suffix(n + 1 , 0);
        suffix[n - 1] = nums[n - 1];
        
        for(int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + nums[i];
        }
        
        int prefix = 0;
        for(int i = 0; i < n; i++) {
            if(prefix == suffix[i + 1]) {
                return i;
            }
            prefix += nums[i];
        }
        
        return -1;
    }
};