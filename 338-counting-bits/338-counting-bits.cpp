class Solution {
public:
    vector<int> countBits(int n) {
        
        /*
        
        O(N) time and space complexity
        Idea -> Bit Manipulations
        
            1. For an even number i, the no. of bits set will be equal to the no. of bits set in i/2
               Because, 2 * i is just the left shift of i
            2. For an odd number i, the no. of bits set will be equal to the no. of bits set in i / 2 + 1
               Because, 2 * i + 1 is left shift of i and the last bit is set.
        
        */
        
        vector <int> dp(n + 1 , 0);

        for(int i = 1; i <= n; i++) {
            dp[i] = dp[i / 2] + i % 2;
        }
        
        return dp;
    }
};