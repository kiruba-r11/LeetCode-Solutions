class Solution {
public:
    int minimumCardPickup(vector<int>& nums) {
        int n = nums.size();
        int i = 0 , j = 0 , ans = n + 1;
        unordered_map <int , int> hash;
        
        while(j < n) {
            if(hash[nums[j]] == 0) {
                hash[nums[j]]++;
                j++;
            } else {
                while(hash[nums[j]] != 0) {
                    hash[nums[i]]--;
                    i++;
                }
                ans = min(ans , j - i + 2);
            }
        }
        
        return ans == n + 1 ? -1 : ans;
    }
};