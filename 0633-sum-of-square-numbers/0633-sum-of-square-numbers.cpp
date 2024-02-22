class Solution {
public:
    int fpow(int b , int p) {
        if(p == 0) return 1;
        int ans = fpow(b * 1LL * b , p / 2);
        if(p & 1) ans = b * ans;
        return ans;
    }
    bool judgeSquareSum(int c) {
        int a = 0 , b = fpow(2 , 16);
        while(a <= b) {
            long long sum = a * 1LL * a + b * 1LL * b;
            if(sum == c) return true;
            if(sum < c) a++;
            else b--;
        }
        
        return false;
    }
};