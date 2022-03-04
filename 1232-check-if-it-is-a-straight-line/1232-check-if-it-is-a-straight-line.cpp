class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        /*
        
        O(N) time and O(1) space complexity
        Idea -> Slope
        
        */
        
        int dx = coordinates[1][0] - coordinates[0][0];
        int dy = coordinates[1][1] - coordinates[0][1];
        
        int n = coordinates.size();
        
        for(int i = 2; i < n; i++) {
            int new_dx = coordinates[i][0] - coordinates[0][0];
            int new_dy = coordinates[i][1] - coordinates[0][1];
            
            if(new_dx * dy != new_dy * dx) return false;
        }
        
        return true;
    }
};