class Solution {
public:
    int countOdds(int low, int high) {
        
        /*
        
        O(1) time and space complexity
        Idea -> Basic Math
        
            1. No. of odd numbers from 1 to high -> ceil(high / 2);
            2. No. of odd numbers from 1 to low (excluding low) -> floor(low / 2);
            3. No. of odd numbers from low to high -> ceil(high / 2) - floor(low / 2);
        
        */
        
        int ans = (high / 2 + high % 2) - (low / 2);
        
        return ans;
    }
};
