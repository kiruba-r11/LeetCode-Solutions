class Solution {
public:
    int pivotInteger(int n) {
        int total = n * (n + 1) / 2;
        
        for(int i = 1; i <= n; i++) {
            int prefix = i * (i + 1) / 2;
            int suffix = total - prefix + i;
            if(prefix == suffix) return i;
        }
        
        return -1;
    }
};