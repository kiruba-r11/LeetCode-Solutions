class Solution {
public:
    int arraySign(vector<int>& nums) {
        
        /*
        
        O(N) time and O(1) space complexity
        Idea -> 
        
            1. If no. of negative elements is odd, the product is negative
            2. If there is more than one zero, the product is zero
        
        */
        
        int neg = 0;
        for(auto i: nums) {
            if(i == 0) return 0;
            if(i < 0) neg++;
        }
        
        return neg & 1 ? -1 : 1;
    }
};