class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        /*
        
        O(No. of bits) time and O(1) space complexity
        Idea -> Brian Kernighan's Algorithm
        
        */
        
        if(n <= 0) return false;
        
        int bits = 0;
        
        while(n) {
            n = n & (n - 1);
            bits++;
        }
        
        return bits == 1;
    }
};
