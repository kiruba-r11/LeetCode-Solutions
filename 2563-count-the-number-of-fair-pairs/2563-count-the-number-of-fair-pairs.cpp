class Solution {
public:
    int find(vector <int> &nums , int key) {
        int n = nums.size();
        int low = 0 , high = n - 1;
        int ans = -1;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] <= key) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
    
    long long solve(vector <int> &nums , int limit) {
    
        int n = nums.size();
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            int idx = find(nums , limit - nums[i]);
            if(idx > i) ans += idx - i;
        }
        
        return ans;
    }
    
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin() , nums.end());
        
        long long up = solve(nums , upper);
        long long low = solve(nums , lower - 1);
        
        return up - low;
    }
};

