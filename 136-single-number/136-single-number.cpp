class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /*
        
        O(N) time and O(1) space complexity
        Idea -> Bit Manipulations (XOR)
        
        XOR properties : 
            1. a ^ a = 0
            2. a ^ 0 (or) 0 ^ a = a
            
        Therefore, if every element occurs twice, the xor of all will become zero. The xor of zero and the element that occurs only once gives the element itself.
        
        */
        
        int xor_ = 0;
        for(auto i: nums) {
            xor_ ^= i;
        }
        
        return xor_;
    }
};