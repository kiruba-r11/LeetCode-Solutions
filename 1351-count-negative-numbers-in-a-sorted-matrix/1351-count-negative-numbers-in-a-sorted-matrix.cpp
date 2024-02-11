class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        int i = 0 , j = m - 1;
        while(i <= n - 1 && j >= 0) {
            if(grid[i][j] < 0) {
                ans += n - i;
                j--;
            } else {
                i++;
            }
        }
        
        return ans;
    }
};