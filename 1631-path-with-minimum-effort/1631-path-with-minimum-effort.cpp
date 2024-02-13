class Solution {
public:
    vector <pair <int , int>> dirs = {{-1 , 0} , {1 , 0} , {0 , 1} , {0 , -1}};
    
    bool solve(vector <vector <int>> &heights , int row , int col , int range , int prev , vector <vector <bool>> &visited) {

        if(row < 0 || row >= heights.size() || col < 0 || col >= heights[0].size() || visited[row][col] == true) return false;
        if(abs(prev - heights[row][col]) > range) return false;
        
        if(row == heights.size() - 1 && col == heights[0].size() - 1) return true;
        
        visited[row][col] = true;
        for(auto dir: dirs) {
            int x = dir.first;
            int y = dir.second;
            
            if(solve(heights , row + x , col + y , range , heights[row][col] , visited)) return true;
        }
        
        // visited[row][col] = false;
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int low = 0 , high = 1e6;
        int ans = high;
        int n = heights.size();
        int m = heights[0].size();
        while(low <= high) {
            int mid = low + (high - low) / 2;
            vector <vector <bool>> visited(n , vector <bool> (m));
            bool check = solve(heights , 0 , 0 , mid , heights[0][0] , visited);
            if(check) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};