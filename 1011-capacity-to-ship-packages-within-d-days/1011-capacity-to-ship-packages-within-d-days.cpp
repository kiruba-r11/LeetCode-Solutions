class Solution {
public:
    bool ship(vector <int> &weights , int capacity , int days) {
        int n = weights.size();
        int cur = 0;
        for(int i = 0; i < n; i++) {
            if(weights[i] > capacity) return false;
            if(cur + weights[i] <= capacity) cur += weights[i];
            else {
                if(days == 0) return false;
                days--;
                cur = weights[i];
            }
        }
        return days >= 1;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 1 , high = 25 * (1e6);
        int ans = high;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            bool possible = ship(weights , mid , days);
            if(possible) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};