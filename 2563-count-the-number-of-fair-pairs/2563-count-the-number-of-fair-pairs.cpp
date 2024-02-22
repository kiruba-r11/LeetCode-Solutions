class Solution {
public:
    int bslb(vector <int> &nums , int key , int low , int high) {
    
        int n = nums.size();
        int ans = n;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] >= key) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            } 
        }
        
        return ans;
    }
    
    int bsub(vector <int> &nums , int key , int low , int high) {
        
        int n = nums.size();
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
    
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin() , nums.end());
        
        int n = nums.size();
        long long ans = 0;
        
        for(int i = 0; i < n; i++) {
            int lb = lower - nums[i];
            int ub = upper - nums[i];
            int li = bslb(nums , lb , i + 1 , n - 1);
            int ui = bsub(nums , ub , i + 1 , n - 1);

            int cnt = ui - li + 1;
            ans += cnt >= 0 ? cnt : 0;
        }
        
        return ans;
    }
    
};

