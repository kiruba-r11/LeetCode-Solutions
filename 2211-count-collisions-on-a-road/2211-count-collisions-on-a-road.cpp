class Solution {
public:
    int countCollisions(string dir) {
        
        /*
        
        O(N) time and O(1) space complexity
        Idea ->
        
            1. The cars moving left from index 0 will not collide
            2. For every car moving right,
                2.1. If there is a car that is not moving, then
                        No. of collisions = No. of right cars
                2.2. If there is a car that is moving left, then
                        No. of collisions = No. of right cars + 1
         
        */
        
        int right = 0 , ans = 0 , n = dir.size();
        
        int i = 0;
        while(i < n && dir[i] == 'L') i++;
        
        for(; i < n; i++) {
            if(dir[i] == 'R') right++;
            else {
                ans += right + (dir[i] == 'L');
                right = 0;
            }
        }
        
        return ans;
    }
};