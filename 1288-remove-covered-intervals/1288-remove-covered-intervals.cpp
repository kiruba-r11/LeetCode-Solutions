class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& nums) {
        
        /*
        
        O(NlogN) time and O(1) space complexity
        Idea -> Sorting
        
        Intuition:
            1. Sort the array based on the starting point
            2. Now, there might exist three case,
                2.1. [a , b] , [c , d], here a >= c && b <= d. Which means [c , d] contains [a , b]
                2.2. [a , b] , [c , d], here c >= a && d <= b. Which means [a , b] contains [c , d]
                2.3. [a , b] , [c , d], other cases
                
                Here, in the first and second case, we can represent as one interval. But in the third case, we can't do that, we have to represent them as two different intervals.
        
        */
        
        sort(nums.begin() , nums.end());
        
        vector <int> cur;
        int n = nums.size();
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            if(cur.size() == 0) {
                cur = nums[i];
            } else {
                if(cur[0] >= nums[i][0] && cur[1] <= nums[i][1]) cur = nums[i];
                else if(cur[0] <= nums[i][0] && cur[1] >= nums[i][1]) continue;
                else {
                    ans++;
                    cur = nums[i];
                }
            }
        }
        return ans + 1;
    }
};