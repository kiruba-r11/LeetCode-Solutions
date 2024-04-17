class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        map <int , int> hash;
        for(int i = 0; i < n; i++) {
            if(hash.find(nums[i]) == hash.end()) {
                hash[nums[i]] = i;
            } else {
                int ti = hash[nums[i]];
                int tj = i;
                if(abs(ti - tj) <= k) return true;
                hash[nums[i]] = i;
            }
        }
        
        return false;
    }
};