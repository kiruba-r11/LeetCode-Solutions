class Solution {
public:
    int concatenatedBinary(int n) {
        /*
        
        O(N) time and O(1) space complexity
        Idea -> 
        
            No. of bits in 
                1 -> 1 (power of 2)
                2 -> 2 (power of 2)
                3 -> 2
                4 -> 3 (power of 2)
                5 -> 3
                6 -> 3
                7 -> 3
                8 -> 4 (power of 2)
                ...
                
            For every power of 2, the no. of bits gets increased by one.
            
            The idea is to shift the cur result by (no. of bits) positions and add the value to the result.
            And for every power of two, no. of bits is incremented by 1.
        
        */
        
        long long ans = 0;
        int bits = 1;
        int mod = (int)1e9 + 7;
        
        for(int i = 1; i <= n; i++) {
            if(i != 1 && (i & (i - 1)) == 0) bits++;
            
            ans = ((ans << bits) + i) % mod;
        }
        
        return (int)ans;
    }
};