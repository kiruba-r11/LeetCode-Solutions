class Solution {
public:
    bool condition(vector <int> &dist , double hour , int speed) {
    
        int n = dist.size();
        double time = 0;
        for(int i = 0; i < n; i++) {
            if(i == n - 1) time += ((double)dist[i]) / speed;
            else time += dist[i] / speed + (dist[i] % speed != 0);
        }
        
        return time <= hour;
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low = 1 , high = 1e9;
        int ans = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(condition(dist , hour , mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};