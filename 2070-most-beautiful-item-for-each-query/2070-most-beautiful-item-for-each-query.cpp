class Solution {
public:
    int bs(vector <vector <int>> &nums , int key) {
        int n = nums.size();
        int low = 0 , high = n - 1;
        int ans = -1;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid][0] <= key) {
                ans = max(ans , nums[mid][1]);
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans == -1 ? 0 : ans;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin() , items.end());
        int m = items.size();
        for(int i = 1; i < m; i++) {
            items[i][1] = max(items[i][1] , items[i - 1][1]);
        }
        
        int n = queries.size();
        vector <int> ans(n);
        for(int i = 0; i < n; i++) {
            ans[i] = bs(items , queries[i]);
        }
        return ans;
    }
};