class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int maxFreq = 0;
        int i = 0 , j = 0;
        int ans = 0;
        
        map <int , int> hash;
        
        while(j < n) {
            hash[nums[j]]++;
            maxFreq = max(maxFreq , hash[nums[j]]);
            if(j - i + 1 - maxFreq > k) {
                // if(hash[nums[i]] == maxFreq) maxFreq--;
                hash[nums[i]]--;
                if(hash[nums[i]] == 0) hash.erase(nums[i]);
                i++;
            }
            if(j - i + 1 - maxFreq <= k) ans = max(ans , maxFreq);
            j++;
        }
        
        return ans;
    }
};