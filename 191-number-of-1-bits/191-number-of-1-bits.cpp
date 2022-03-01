class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        /*
        
        O(No. of bits) time and O(1) space complexity
        Idea -> Brian Kernighan's Algorithm
        
        */
        
        int bits = 0;
        while(n > 0) {
            bits++;
            n = n & (n - 1);
        }
        
        return bits;
    }
};