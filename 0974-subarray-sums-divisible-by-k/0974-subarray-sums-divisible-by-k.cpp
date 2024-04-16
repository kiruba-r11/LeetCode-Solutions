class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // Premise
        // 1. sum(nums[i1..i2]) % k == x
        // 2. sum(nums[i1..i3]) % k == x
        // Then, sum(nums[i2+1..i3]) % k == 0 -> len = i3 - i2. Maximise this len
        
        int n = nums.size();
        int sum = 0;
        int ans = 0;
        map <int , int> hash;
        hash[sum] = 1;
        
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            ans += hash[(k + sum % k) % k];
            hash[(k + sum % k) % k]++;
        }
        
        return ans;
    }
};
