class Solution {
public:
    int mod = 1000000007;
    long long fpow(long long base , long long power) {
    
        if(power == 0) return 1;
        
        long long store = fpow(((base % mod) * (base % mod)) % mod , power / 2);
        if(power & 1) return ((store % mod) * (base % mod)) % mod;
        return store % mod;
    }
    
    int countGoodNumbers(long long n) {
        long long even = fpow(5 , n / 2 + n % 2) % mod;
        long long odd = fpow(4 , n / 2) % mod;
        
        long long ans = (even * odd) % mod;
        return ans;
    }
};

