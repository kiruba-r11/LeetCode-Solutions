class Solution {
public:
    
    int maxsum = 0;
    vector <pair <int , int>> dirs = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};
    void solve(vector <vector <int>> &grid , int i , int j , int &cursum) {
    
        if(i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j] == 0) return;
        
        cursum += grid[i][j];
        int temp = grid[i][j];
        grid[i][j] = 0;
        for(auto dir: dirs) {
            int x = dir.first;
            int y = dir.second;
            
            solve(grid , i + x , j + y , cursum);
        }
        maxsum = max(maxsum , cursum);
        grid[i][j] = temp;
        cursum -= grid[i][j];
    }
    
    
    int getMaximumGold(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] != 0) {
                    int cursum = 0;
                    solve(grid , i , j , cursum);
                }
            }
        }
        
        return maxsum;
    }
};