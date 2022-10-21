class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map <int , int> hash;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(hash.find(nums[i]) == hash.end()) hash[nums[i]] = i;
            else {
                if(abs(i - hash[nums[i]]) <= k) return true;
                hash[nums[i]] = i;
            }
        }
        
        return false;
    }
};