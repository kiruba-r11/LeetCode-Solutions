class Solution {
public:
    double fpow(double base , int pow) {
        if(pow == 0) return 1.0;
        double ans = fpow(base * base , pow / 2);
        if(pow & 1) ans = ans * base;
        return ans;
    }
    
    double myPow(double x, int n) {
        int base_neg = 0;
        int pow_neg = 0;
        if(x < 0) base_neg = 1;
        if(n < 0) pow_neg = 1;
        
        x = abs(x);
        n = abs(n);

        double val = fpow(x , n);
        if(!base_neg && !pow_neg) return val;
        if(base_neg && !pow_neg) return (n & 1) ? -1.0 * val : val;
        if(!base_neg && pow_neg) return 1.0/val;
        return (n & 1) ? -1.0/val : 1.0/val;
    }
};