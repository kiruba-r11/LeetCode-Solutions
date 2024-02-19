class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int index = -1; // represents the index till which we have even elements
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if((nums[i] & 1) == 0) {
                swap(nums[index + 1] , nums[i]);
                index++;
            }
        }
        return nums;
    }
};