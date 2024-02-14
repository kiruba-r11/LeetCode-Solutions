class Solution {
public:
    bool searchMatrix(vector<vector<int>>& grid, int target) {
        int n = grid.size() , m = grid[0].size();
        int low = 1 , high = m * n;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int row = mid / m + (mid % m != 0);
            int col = mid - m * (row - 1);
            if(grid[row - 1][col - 1] == target) return true;
            else if(grid[row - 1][col - 1] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return false;
    }
};