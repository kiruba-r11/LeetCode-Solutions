class Solution {
public:
    int mod = 1e9 + 7;
    int fpow(long long b , long long p) {
        if(p == 0) return 1;
        if(p & 1) return b * fpow((b * b) % mod , p / 2) % mod;
        return fpow((b * b) % mod , p / 2) % mod;
    }
    int countGoodNumbers(long long n) {
        long long four = n / 2;
        long long five = n / 2 + n % 2;
        
        return ((fpow(4 , four) % mod)  * 1L * (fpow(5 , five) % mod) % mod);
    }
};