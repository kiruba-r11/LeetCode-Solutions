class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector <int> prefix(1001);
        int n = trips.size();
        
        for(int i = 0; i < n; i++) {
            prefix[trips[i][1]] += trips[i][0];
            prefix[trips[i][2]] -= trips[i][0];
        }
        
        if(prefix[0] > capacity) return false;
        
        for(int i = 1; i <= 1000; i++) {
            prefix[i] += prefix[i - 1];
            if(prefix[i] > capacity) return false;
        }
        
        return true;
    }
};