class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long ans = (n * 1L * (n - 1)) / 2;
        
        map <int , int> prefix;
        
        for(int i = 0; i < n; i++) {
            int count = prefix[nums[i] - i];
            ans -= count;
            
            prefix[nums[i] - i]++;
        }
        
        return ans;
    }
};