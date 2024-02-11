class Solution {
public:
    int bs(vector <int> &nums) {
        int n = nums.size();
        int low = 0 , high = n - 1;
        int ans = n;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] <= -1) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int pos = bs(grid[i]);
            ans += m - pos;
        }
        
        return ans;
    }
};