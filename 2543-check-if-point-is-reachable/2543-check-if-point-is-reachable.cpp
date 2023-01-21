class Solution {
public:
    int divide(int x) {
        while(x % 2 == 0) x /= 2;
        return x;
    }
    
    bool solve(int x , int y) {
        
        if(x == 1 || y == 1) return true;
        if(x == y) return false;
        
        int n = divide(x + y);
        
        if(x < y) return solve(x , n);
        return solve(n , y);
    }
    
    bool isReachable(int xx, int yy) {
        int x = divide(xx);
        int y = divide(yy);
        
        return solve(x , y);
    }
};