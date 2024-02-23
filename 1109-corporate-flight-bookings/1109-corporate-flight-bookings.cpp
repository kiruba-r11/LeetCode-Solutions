class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        
        vector <int> ans(n);
        int m = bookings.size();
        
        for(int i = 0; i < m; i++) {
            int first = bookings[i][0] - 1;
            int last = bookings[i][1] - 1;
            
            ans[first] += bookings[i][2];
            if(last != n - 1) ans[last + 1] -= bookings[i][2];
        }

        for(int i = 1; i < n; i++) ans[i] += ans[i - 1];
        
        return ans;
    }
};