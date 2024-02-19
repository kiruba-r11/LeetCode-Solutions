class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0 , j = n - 1;
        int count = 0;
        sort(nums.begin() , nums.end());
        
        while(i < j) {
            int sum = nums[i] + nums[j];
            if(sum < target) {
                count += j - i;
                i++;
            } else {
                j--;
            }
        }
        
        return count;
    }
};

// sum < target -> count, increase sum, move the left pointer
// sum = target -> decrease sum, move the right pointer
// sum > target -> decrease sum, move the right pointer