class Solution {
public:
    static bool cmp(vector <int> &a , vector <int> &b) {
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin() , points.end() , cmp);
        
        // Sort the arrows based on the ending point
        // The idea is, for a current ending point, if the start point of another
        // balloon is lesser than or equal to that balloon, then it can be merged 
        // because its ending point is surely greater than or equal to the current 
        // balloon's ending point. If not, take that balloon as the new marker and 
        // increase the arrow.
        
        
        int arrow = 1;
        
        int prev = points[0][1];
        
        for(int i = 1; i < points.size(); i++) {
            if(points[i][0] <= prev) {
                continue;
            } else {
                arrow++;
                prev = points[i][1];
            }
        }
        
        return arrow;
    }
};