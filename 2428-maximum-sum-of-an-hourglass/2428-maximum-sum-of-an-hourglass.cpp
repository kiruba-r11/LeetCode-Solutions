class Solution {
public:
    
    bool inbounds(vector <vector <int>> &grid , int row , int col) {
        int n = grid.size();
        int m = grid[0].size();
        
        if(row + 2 >= n || col + 2 >= m) return false;
        return true;
    }
    
    int calc(vector <vector <int>> &grid , int row , int col) {
    
        if(inbounds(grid , row , col) == false) return 0;
        
        vector <pair <int , int>> dirs = {
            {0 , 0} , {0 , 1} , {0 , 2}, {1 , 1} , {2 , 0} , {2 , 1} , {2 , 2}
        };
        
        int sum = 0;
        
        for(auto dir: dirs) {
            int x = dir.first;
            int y = dir.second;
            
            sum += grid[row + x][col + y];
        }
        return sum;
    }
    
    int maxSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans = max(ans , calc(grid , i , j));
            }
        }
        
        return ans;
    }
};