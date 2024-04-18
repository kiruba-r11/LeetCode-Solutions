class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        int n = nums.size();
        long long sum = 0;
        
        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }
        
        int k = target / sum; // no. of times the complete array sum is required to fill the target
        if(k * sum == target) return k * n;
        
        target -= k * sum;
        map <int , int> hash;
        hash[sum] = -1;
        
        int i = 0;
        int ans = INT_MAX;
        while(i < 2 * n) {
            int idx = i % n;
            sum += nums[idx];
            
            if(hash.find(sum - target) != hash.end()) ans = min(ans , i - hash[sum - target]);
            
            hash[sum] = i;
            i++;
        }
        
        return ans == INT_MAX ? -1 : ans + k * n;
    }
};