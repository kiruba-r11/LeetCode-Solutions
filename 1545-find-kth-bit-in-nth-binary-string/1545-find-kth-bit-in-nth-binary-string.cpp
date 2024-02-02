class Solution {
public:
    char findBit(int n , int k , int n1) {
        if(n == 1) return '0';
        
        int mid = n1 / 2;
        
        if(k == mid) return '1';
        if(k < mid) return findBit(n - 1 , k , n1 / 2);
        
        if(findBit(n - 1 , 2 * mid - k , n1 / 2) == '1') return '0';
        return '1';
    }
    
    int fpow(int b , int p) {
        if(p == 0) return 1;
        int ans = fpow(b * 1L * b , p / 2);
        if(p & 1) return b * ans;
        return ans;
    }
    
    char findKthBit(int n, int k) {
        int n1 = fpow(2 , n);
        return findBit(n , k , n1);
    }
};