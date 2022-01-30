class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i = 0 , j = 0 , n = nums.size() , sum = 0 , maxsum = 0;
        unordered_map <int , int> hash;
        
        while(j < n) {
            // sum = 0;
            // cnt = 0;
            while(j < n && hash[nums[j]] == 0) {
                sum += nums[j];
                hash[nums[j]]++;
                j++;
                // cnt++;
            }
            maxsum = max(sum , maxsum);
            while(i < j && j < n && hash[nums[j]] == 1) {
                sum -= nums[i];
                hash[nums[i]]--;
                i++;
            }
        }
        return maxsum;
    }
};