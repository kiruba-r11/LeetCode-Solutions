class Solution {
public:
    bool possible(vector <int> &price , int mid , int k) {
        
        int n = price.size();
        int cnt = 0;
        for(int i = 1 , j = 0; i < n && j < n; i++) {
            if(price[i] - price[j] >= mid) {
                cnt++;
                j = i;
            }
        }
        return cnt >= k - 1;
    }
    
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin() , price.end());
        int n = price.size();
        int low = 0 , high = price[n - 1] - price[0];
        int ans = low;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(possible(price , mid , k)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};
