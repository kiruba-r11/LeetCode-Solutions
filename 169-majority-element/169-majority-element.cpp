class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        /*
        
        O(N) time and O(1) space complexity
        Idea -> Boyer Moore's Voting Algorithm
        
        */
        
        int voter = nums[0] , count = 1 , n = nums.size();
        for(int i = 1; i < n; i++) {
            if(nums[i] == voter) count++;
            else {
                count--;
                if(count < 0) {
                    voter = nums[i];
                    count = 1;
                }
            }
        }
        
        return voter;
    }
};