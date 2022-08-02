class Solution {
public:
    int kthSmallest(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        
        vector <int> store;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                store.push_back(grid[i][j]);
            }
        }
        
        sort(store.begin() , store.end());
        return store[k - 1];
    }
};