class Solution {
public:
    int fpow(int b , int p) {
        int pow = 1;
        while(p > 0) {
            if(p & 1)
                pow = pow * b;
            b = b * b;
            p = p >> 1;
        }
        return pow;
    }
    int maximum69Number (int num) {
        bool check = false;
        int val = 1 , i = 1 , pos = -1;
        int temp = num;
        while(num > 0) {
            if(num % 10 == 6) 
                pos = i;
            num /= 10;
            i++;
        }
        if(pos != -1) {
            val = fpow(10 , pos - 1) * 3;
            temp += val;
        }
        return temp;
    }
};