class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0;
        int n = nums.size();
        for(int i = 1; i < n; i++) {
            if(nums[i] != nums[index]) {
                swap(nums[i] , nums[index + 1]);
                index++;
            }
        }
        
        return index + 1;
    }
};