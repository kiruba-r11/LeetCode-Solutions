class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int index = -1;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            if(!(nums[i] & 1)) {
                swap(nums[index + 1] , nums[i]);
                index++;
            }
        }
        return nums;
    }
};