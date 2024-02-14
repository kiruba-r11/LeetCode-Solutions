class Solution {
public:
    bool condition(vector <int> &nums , int days , int m , int k) {
    
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int j = i;
            while(j < n && nums[j] <= days) {
                if((j - i + 1) == k) {
                    m--;
                    break;
                }
                j++;
            }
            
            i = j;
        }
        return m <= 0;
    }
    
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int low = bloomDay[0] , high = bloomDay[0];
        
        for(int i = 1; i < n; i++) {
            low = min(low , bloomDay[i]);
            high = max(high , bloomDay[i]);
        }
        
        int ans = 1e9 + 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(condition(bloomDay , mid , m , k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans == 1e9 + 1 ? -1 : ans;
    }
};