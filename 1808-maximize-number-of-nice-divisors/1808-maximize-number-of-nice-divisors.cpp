class Solution {
public:
    long long fpow(long long base , int pow , int mod) {
    
        if(pow == 0) return 1;
        long long ans = fpow(((base % mod) * (base % mod)) % mod , pow / 2 , mod);
        if(pow & 1) ans = ((ans % mod) * (base % mod)) % mod;
        return ans;
    }
    
    int maxNiceDivisors(int p) {
        if(p <= 3) return p;
        
        int three = p / 3;
        int mod = 1e9 + 7;
        if(p % 3 == 0) return fpow(3 , three , mod);
        if(p % 3 == 2) return (2 * (fpow(3 , three , mod) % mod)) % mod;
        if(p % 3 == 1) return (4 * (fpow(3 , three - 1 , mod) % mod)) % mod;
        return 0;
    }
};
    