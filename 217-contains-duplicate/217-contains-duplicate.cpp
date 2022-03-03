class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        /*
        
        O(NlogN) time and O(1) space complexity
        Idea -> Sorting 
        
            1. If element is not distinct, it is equal to its adjacent
            2. There can also be a solution for O(N) time and O(N) space complexity
        
        */
        
        sort(nums.begin() , nums.end());
        
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int j = i + 1;
            if(j < n && nums[i] == nums[j]) return true;
        }
        
        return false;
    }
};



