class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        /*
        
        O(N) time and O(1) space complexity
        Idea -> Two pointers
        
        */
        
        int low = 0 , high = nums.size() - 1;
        
        while(low < high) {
            int sum = nums[low] + nums[high];
            if(sum == target) return {low + 1 , high + 1};
            if(sum < target) low++;
            else high--;
        }
        
        return {};
    }
};