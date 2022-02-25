class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        
        /*
        
        O(logN) time and O(1) space complexity
        Idea -> 
            1. For example, let the bit representation be
                L -> ...000001111100101001
                R -> ...000100100100010001
                
            2. Here, the ans will have unset bits where ever L and R are unset
            3. Also, for an unset bit in L, all the bits right to it can take any values. This would result in 0 if we take AND for all of them.
            4. So, the common prefix of L and R would be ans.
        
        */
        
        int bits = 0;
        while(left != right) {
            bits++;
            left /= 2;
            right /= 2;
        }
        
        if(left == 0) return 0;
        
        while(bits--) left *= 2;
        
        return left;
    }
};