class Solution {
public:
    long long coloredCells(int n) {
        long long ans = n * 1L * n + (n - 1) * 1L * (n - 1);
        return ans;
    }
};