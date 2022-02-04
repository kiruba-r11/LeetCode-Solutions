class Solution {
public:
    int findMaxLength(vector<int>& nums) {
     
        unordered_map <int , int> hash;
        hash[0] = -1;
        
        int n = nums.size() , ans = 0;
        
        for(int i = 0; i < n; i++) {
            nums[i] = nums[i] ? 1 : -1;
            if(i != 0) 
                nums[i] += nums[i - 1];
            
            if(hash.find(nums[i]) == hash.end()) hash[nums[i]] = i;
            else {
                ans = max(ans , i - hash[nums[i]]);
            }
        }
        
        return ans;
    }
};