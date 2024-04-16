class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int ans = 0;
        map <int , int> hash;
        hash[sum] = -1;
        
        for(int i = 0; i < n; i++) {
            sum += nums[i] == 1 ? 1 : -1;
            if(hash.find(sum) == hash.end()) hash[sum] = i;
            else ans = max(ans , i - hash[sum]);
        }
        
        return ans;
    }
};