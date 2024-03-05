class Solution {
public:
    long long fpow(long long x , long long y , int p) {
    
        int res = 1;
        while (y > 0) {
            if (y % 2 == 1)
                res = (res * x) % p;
            y = y >> 1;
            x = (x * x) % p;
        }
        return res % p;
    }
    
    int monkeyMove(int n) {
        int m = 1e9 + 7;
        long long ans = fpow(2 , n , m);
        ans = (ans - 2 + m) % m;
        return ans;
        if(ans <= 2) return 2 * n;
        return (int) ans - 2;
    }
};