class Solution {
public:
    int mod = 1e9 + 7;
    long long fpow(long long base , long long power) {
        if(power == 0) return 1;
        
        long long result = fpow((base * 1LL * base) % mod , power / 2) % mod;
        if(power & 1) return (base * result) % mod;
        return result;
    }
    
    int countGoodNumbers(long long n) {
        long long even_pos = n % 2 + n / 2;
        long long odd_pos = n / 2;
        
        long long even_ans = fpow(5 , even_pos) % mod;
        long long odd_ans = fpow(4 , odd_pos) % mod;
        
        long long ans = (even_ans * 1LL * odd_ans) % mod;
        return (int)ans;
    }
};







