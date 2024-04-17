class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int sum = 0;
        int ans = 0;
        map <int , int> hash;
        hash[sum] = 1;
        
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            ans += hash[sum - goal];
            hash[sum]++;
        }
        
        return ans;
    }
};