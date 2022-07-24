class Solution {
public:
    long long c(int n , int r) {
    
        long long res = 1;
        
        for(int i = n , j = 1; i >= r + 1; i-- , j++) {
            res = res * i;
            res = res / j;
        }
        
        return res;
    }
    
    int numTrees(int n) {
        int ans = c(2 * n , n) / (n + 1);
        return ans;
    }
};