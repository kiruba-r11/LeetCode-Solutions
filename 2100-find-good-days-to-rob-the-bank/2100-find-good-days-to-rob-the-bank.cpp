class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& nums, int time) {
        // Sorted Prefix Sum pattern
        int n = nums.size();
        vector <int> prefix(n , 1);
        vector <int> suffix(n , 1);
        
        for(int i = 1; i < n; i++) {
            if(nums[i - 1] >= nums[i]) {
                prefix[i] = prefix[i - 1] + 1;
            }
        }
        
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] <= nums[i + 1]) {
                suffix[i] = suffix[i + 1] + 1;
            }
        }
        
        vector <int> ans;
        for(int i = time; i < n - time; i++) {
            if(prefix[i] >= time + 1 && suffix[i] >= time + 1) ans.push_back(i);
        }
        
        return ans;
    }
};