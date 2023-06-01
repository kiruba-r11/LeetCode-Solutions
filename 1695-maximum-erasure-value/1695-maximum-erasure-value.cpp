class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_map <int , int> hash;
        
        int i = 0 , j = 0 , cursum = 0 , sum = 0;
        while(j < n) {
            if(hash[nums[j]] == 0) {
                hash[nums[j]]++;
                cursum += nums[j];
                j++;
                
                sum = max(sum , cursum);
            } else {
                while(hash[nums[j]] != 0) {
                    hash[nums[i]]--;
                    cursum -= nums[i];
                    i++;
                }
            }
        }
        
        return sum;
    }
};