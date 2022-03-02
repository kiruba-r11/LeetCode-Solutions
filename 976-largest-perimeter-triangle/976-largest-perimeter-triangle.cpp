class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        
        /*
        
        O(N) time and O(1) space complexity
        Idea -> Triangle Property + Sorting
        
        We know for a triangle with sides a, b, c, it must satisfy (a + b > c)
        Now, we just need to maximise the value of a + b and c to have maximum perimeter
        
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