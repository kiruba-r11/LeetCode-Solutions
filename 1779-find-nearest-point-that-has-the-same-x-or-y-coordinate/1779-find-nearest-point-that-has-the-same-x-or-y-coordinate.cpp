class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        
        /*
        
        O(N) time and O(1) space complexity
        Idea -> Array Traversal
        
        */
        
        int n = points.size() , ans = -1;
        
        for(int i = 0; i < n; i++) {
            bool isValid = false;
            if(points[i][0] == x || points[i][1] == y) isValid = true;
            
            if(ans != -1 && isValid) {
                int prevDist = abs(x - points[ans][0]) + abs(y - points[ans][1]);
                int newDist = abs(x - points[i][0]) + abs(y - points[i][1]);
                
                if(newDist < prevDist) ans = i;
            } else if(isValid) {
                ans = i;
            }
        }
        
        return ans;
    }
};