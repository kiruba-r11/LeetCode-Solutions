class Solution {
public:
    int fpow(long long x, unsigned int y, int p) {
        int res = 1;     
        x = x % p; 
        if (x == 0) return 0;
        while (y > 0) {
            if (y & 1)
                res = (res*x) % p;
            y = y>>1; 
            x = (x*x) % p;
        }
        return res;
    }
    
    int countWays(vector<vector<int>>& ranges) {
        // stack <pair <int , int>> s;
        int cnt = 0;
        pair <int , int> s;
        int n = ranges.size();
        sort(ranges.begin() , ranges.end());
        
        for(int i = 0; i < n; i++) {
            if(cnt == 0 || s.second < ranges[i][0]) {
                s = {ranges[i][0] , ranges[i][1]};
                cnt++;
            } else {
                s.second = max(s.second , ranges[i][1]);
            }
            // if(s.empty() || s.top().second < ranges[i][0]) {
            //     s.push({ranges[i][0] , ranges[i][1]});
            // } else {
            //     pair <int , int> tp = s.top();
            //     s.pop();
            //     tp.second = max(tp.second , ranges[i][1]);
            //     s.push(tp);
            // }
        }
        
        // int cnt = s.size();

        return fpow(2 , cnt , 1e9 + 7);
    }
};