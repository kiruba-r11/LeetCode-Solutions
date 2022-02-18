class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        /*
        
        O(N) Time and O(1) space complexity
        Idea -> Two Pointers
        
        One pointer is used to traverse the array, and the second pointer always stays at the index which has the value zero.
        Now if, the fast pointer finds a non-zero element, we can swap that with the slow pointer, and move the slow pointer since, this index now does not contain zero.
        
        */
        
        int zeroth = 0 , n = nums.size();
        
        for(int i = 0; i < n; i++) {
            if(nums[i] != 0) {
                swap(nums[zeroth] , nums[i]);
                zeroth++;
            }    
        }
    }
};