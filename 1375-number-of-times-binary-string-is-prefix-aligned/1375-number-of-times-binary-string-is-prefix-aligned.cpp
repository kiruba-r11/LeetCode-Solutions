class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        
        /*
        
        O(N) time and O(1) space complexity
        Idea -> Prefix Max
        
        We know that for a string to be prefix alligned, all the bits from [1 , i] (some i <= n) should be set. Which basically means if a bit 'i' is set, all the bits before 'i' should also be set. So, it comes to a point that, the length of string from (0 to i) must be equal to the ith set bit.
        
        */
        
        int prefixMax = 0 , n = flips.size() , count = 0;
        
        for(int i = 0; i < n; i++) {
            
            int len = i + 1;
            prefixMax = max(prefixMax , flips[i]);
            
            if(len == prefixMax) count++;
        }
        
        return count;
    }
};