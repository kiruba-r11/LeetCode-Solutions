class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0 , j = 0;
        int sum = 0;
        int ans = 0;
        
        map <int , int> hash;
        
        while(j < n) {
            sum += nums[j];
            hash[nums[j]]++;
            
            while(hash.size() != (j - i + 1)) {
                hash[nums[i]]--;
                sum -= nums[i];
                if(hash[nums[i]] == 0) hash.erase(nums[i]);
                i++;
            }
            
            if(hash.size() == (j - i + 1)) ans = max(ans , sum);
            j++;
        }
        
        return ans;
    }
};