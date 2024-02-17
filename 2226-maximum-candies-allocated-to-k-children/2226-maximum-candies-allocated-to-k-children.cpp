class Solution {
public:
    bool condition(vector <int> &nums , long long cnt , int k) {
    
        int n = nums.size();
        long long num = 0;
        for(int i = 0; i < n; i++) {
            num += nums[i] / k;
        }
        
        return num >= cnt;
    }
    
    int maximumCandies(vector<int>& candies, long long k) {
        long long low = 1 , high = 1e12;
        int ans = 0;
        
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if(condition(candies , k , mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};