class Solution {
public:
    bool solve(vector <int> &piles , int h , int val) {
        if(val == 0) return false;
        
        int n = piles.size();
        long long hr = 0;
        for(int i = 0; i < n; i++) {
            hr += ceil((double)piles[i] / val);
        }
        if(hr > h) return false;
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int low = 0 , high = 0;
        for(auto i: piles) high = max(high , i);
        
        int ans = high;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(solve(piles , h , mid)) {
                ans = min(ans , mid);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};