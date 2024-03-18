class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        // Given 'n' is odd.
        // If we find the first element of the decoded array, we can do the following to find the remaining elements.
        //      decoded[1] = decoded[0] ^ encoded[0]
        //      decoded[2] = decoded[1] ^ encoded[1]
        // ....
        //      decoded[i] = decoded[i - 1] ^ encoded[i - 1], for all i >= 1
            
        // Since, decoded is a permutation of 1..n with n being odd, 
        // total_xor = 1 ^ 2 ^ 3 ^ ... ^ n
        // decoded[0] = (1 ^ 2 ^ 3 ^ ... ^ n) ^ 2 ^ 3 ^ ... ^ n (leaving out the first element decoded[0])
        // decoded[0] = total_xor ^ (2 ^ 3 ^ ... ^ n)
        // decoded[0] = total_xor ^ (perm[1] ^ perm[2] ^ ... ^ perm[n - 1]) (order doesn't matter, since xor is commutative)
        // decoded[0] = total_xor ^ (encoded[1] ^ encoded[3] ^ ... ^ encoded[n - 1]) for n is even
        
        // Then after finding the first element, use the above strategy to find the remainging elements
        
        int m = encoded.size();
        int n = m + 1;
        int total_xor = 0;
        
        vector <int> decoded(n);
        
        for(int i = 1; i <= n; i++) total_xor ^= i;
        for(int i = 1; i < n; i += 2) total_xor ^= encoded[i];
        
        decoded[0] = total_xor;
        
        for(int i = 1; i < n; i++) {
            decoded[i] = decoded[i - 1] ^ encoded[i - 1];
        }
        
        return decoded;
    }
};