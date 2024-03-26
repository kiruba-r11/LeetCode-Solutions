class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long prefix = 0;
        long long sum = 0;
        long long row1 = 0;
        long long row2 = 0;
        
        int n = grid[0].size();
        for(int i = 0; i < n; i++) {
            sum += grid[1][i];
            row1 += grid[0][i];
            row2 += grid[1][i];
        }
        
        long long res = LLONG_MAX;
        // int idx = -1;
        for(int i = 0; i < n; i++) {
            prefix += grid[0][i];
            res = min(res , max(row1 - prefix , row2 - sum));
            // if(prefix + sum > res) {
            //     res = prefix + sum;
            //     idx = i;
            // }
            sum -= grid[1][i];
        }
        
//         for(int i = 0; i <= idx; i++) grid[0][i] = 0;
//         for(int i = n - 1; i >= idx; i--) grid[1][i] = 0;
        
//         sum = 0;
//         prefix = 0;
        
//         for(int i = 0; i < n; i++) sum += grid[1][i];
        
//         for(auto i: grid) {
//             for(auto j: i) cout << j << " ";
//             cout << endl;
//         }
        
//         res = 0;
//         for(int i = 0; i < n; i++) {
//             prefix += grid[0][i];
//             res = max(res , prefix + sum);
//             sum -= grid[1][i];
//         }
        
        return res;
    }
};