class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0 , j = 0 , ans = 0;
        map <int , int> hash;
        
        while(j < n) {
            hash[nums[j]]++;
            while(hash[nums[j]] > k) {
                hash[nums[i]]--;
                i++;
            }
            if(hash[nums[j]] <= k) ans = max(ans , j - i + 1);
            j++;
        }
        
        return ans;
    }
};