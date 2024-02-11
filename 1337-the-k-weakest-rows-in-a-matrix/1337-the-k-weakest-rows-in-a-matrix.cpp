class Solution {
public:
    int bs(vector <int> &nums) {
        int n = nums.size();
        int low = 0 , high = n - 1;
        int ans = n;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] == 0) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        
        priority_queue <pair <int , int>> pq;
        
        for(int i = 0; i < n; i++) {
            int count = bs(mat[i]);
            pq.push({count , i});
            if(pq.size() > k) pq.pop();
        }
        
        vector <int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};
