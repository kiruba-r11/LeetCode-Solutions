class Solution {
public:
    bool condition(vector <int> &nums , int p , int diff) {
        int n = nums.size();
        int prev = 0;
        int cnt = 0;
        
        for(int i = 1; i < n;) {
            bool enter = false;
            while(i < n && nums[i] - nums[prev] <= diff) {
                prev = i + 1;
                i = i + 2;
                cnt++;
                enter = true;
            }
            
            if(!enter) {
                prev = i;
                i++;
            }
        }
        
        if(cnt >= p) return true;
        return false;
    }
    
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin() , nums.end());
        
        int n = nums.size();
        if(n == 1) return 0;
        
        int low = 0 , high = nums[n - 1] - nums[0];
        int ans = 0;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(condition(nums , p , mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};
