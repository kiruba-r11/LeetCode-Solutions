class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();
        int start = 1 , prefix = 1;
        
        for(int i = 0; i < n; i++) {
            prefix = nums[i] + prefix;
            if(prefix < 1) {
                start += abs(prefix) + 1;
                prefix = 1;
            }
        }
        
        return start;
    }
};