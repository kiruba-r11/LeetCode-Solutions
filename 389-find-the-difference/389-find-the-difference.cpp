class Solution {
public:
    char findTheDifference(string s, string t) {
        /*
        
        O(N) time and O(1) space complexity
        Idea -> Bit Manipulations - XOR
        
        Since, except one character all characters in 's' is also in 't' xor of them will cancel out.
        
        */
        
        char ch = ' ';
        int n = s.size();
        
        // Perform Xor 
        for(int i = 0; i < n; i++) {
            ch = ch ^ s[i] ^ t[i];
        }
        
        // Since, our initial character was a space, we need to xor it again with space to make it cancel out
        ch = ch ^ t[n] ^ ' ';
        
        return ch;
    }
};