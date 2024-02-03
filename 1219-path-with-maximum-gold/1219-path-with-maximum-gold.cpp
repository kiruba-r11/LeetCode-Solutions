class Solution {
public:
    vector <pair <int , int>> dirs = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};
    int getGold(vector <vector <int>> &grid , int i , int j) {
    
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0) return 0;
        
        int ans = 0;
        for(auto dir: dirs) {
            int x = dir.first;
            int y = dir.second;
            
            int gold = grid[i][j];
            grid[i][j] = 0;
            ans = max(ans , gold + getGold(grid , i + x , j + y));
            grid[i][j] = gold;
        }
        
        return ans;
    }
    
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] != 0) {
                    ans = max(ans , getGold(grid , i , j));
                }
            }
        }
        
        return ans;
    }
};