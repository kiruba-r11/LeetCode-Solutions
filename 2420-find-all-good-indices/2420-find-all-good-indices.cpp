class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector <pair <int , int>> prefix(n);
        vector <pair <int , int>> suffix(n);
        
        prefix[0] = {1 , -1};
        for(int i = 1; i < n; i++) {
            if(nums[i - 1] >= nums[i]) {
                prefix[i] = prefix[i - 1];
            } else {
                prefix[i] = {0 , i};
            }
        }
        
        suffix[n - 1] = {1 , n};
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] <= nums[i + 1]) {
                suffix[i] = suffix[i + 1];
            } else {
                suffix[i] = {0 , i};
            }
        }
        
        vector <int> ans;
        for(int i = k; i < n - k; i++) {
            int leftval = prefix[i - 1].first;
            int leftidx = prefix[i - 1].second;
            int rightval = suffix[i + 1].first;
            int rightidx = suffix[i + 1].second;
            
            if(leftval == 1 && rightval == 1) {
                ans.push_back(i);
            } else if(leftval == 1) {
                if(rightidx >= i + k) ans.push_back(i);
            } else if(rightval == 1) {
                if(leftidx <= i - k) ans.push_back(i);
            } else {
                if(leftidx <= i - k && rightidx >= i + k) ans.push_back(i);
            }
        }
        
        return ans;
    }
};