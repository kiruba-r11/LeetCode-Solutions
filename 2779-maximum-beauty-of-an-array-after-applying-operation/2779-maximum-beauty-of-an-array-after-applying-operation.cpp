class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        // Line Sweep Algorithm - without defining size
        
        map <int , int> hash;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            hash[nums[i] - k]++;
            hash[nums[i] + k + 1]--;
        }
        
        int ans = 0;
        int prev = 0;
        
        for(auto elem: hash) {
            prev += elem.second;
            ans = max(ans , prev);
        }
        return ans;
    }
};