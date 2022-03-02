class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        
        /*
        
        O(N) time and O(1) space complexity
        
        */
        
        int n = nums.size();
        sort(nums.begin() , nums.end());
        
        for(int i = n - 1; i >= 2; i--) {
            int c = nums[i];
            int b = nums[i - 1];
            int a = nums[i - 2];
            
            if(a + b > c) return a + b + c;
        }
        
        return 0;
    }
};