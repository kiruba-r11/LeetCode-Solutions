class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        /*
        
        O(32) time and O(1) space complexity
        Idea -> If a bit at ith position from LSB is set, set it at the corresponding ith position from MSB
        
        */
        
        uint32_t mask = 0;
        for(int i = 0; i < 32; i++) {
            if(n & (1 << i)) {
                mask |= (1 << (31 - i));
            }
        }
        return mask;
    }
};