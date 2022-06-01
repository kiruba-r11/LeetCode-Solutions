class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum = 0;
        vector<int> a(nums.size());
        for(int i = 0; i < nums.size(); i++)
            a[i] = nums[i];
        for(int i = 0; i < nums.size(); i++) {
            nums[i] = nums[i] + sum;
            sum = a[i] + sum;
        }
        return nums;
    }
};