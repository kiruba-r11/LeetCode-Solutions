class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        pair <int , int> s;
        sort(ranges.begin() , ranges.end());
        
        int n = ranges.size();
        int cnt = 0;
        int ans = 1;
        int mod = 1e9 + 7;
        
        for(int i = 0; i < n; i++) {
            if(cnt == 0 || s.second < ranges[i][0]) {
                s = {ranges[i][0] , ranges[i][1]};
                cnt++;
                ans = ans * 1L * 2;
                ans %= mod;
            } else {
                s.second = max(s.second , ranges[i][1]);
            }
        }

        return ans;
    }
};