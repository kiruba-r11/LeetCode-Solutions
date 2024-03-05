class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n == 1 && k == 1) return 0;
        int val = kthGrammar(n - 1 , k / 2 + k % 2);
        if(k & 1) return val;
        return 1 - val;
    }
};