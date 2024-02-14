class Solution {
public:
    int bs(vector <vector <int>> &nums , int key) {
        
        int n = nums.size();
        int low = 0 , high = n - 1;
        int ans = n;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid][0] >= key) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
    
    vector<int> findRightInterval(vector<vector<int>>& nums) {
        unordered_map <int , int> hash;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            hash[nums[i][0]] = i;
        }
        
        sort(nums.begin() , nums.end());
        
        vector <int> ans(n);
        for(int i = 0; i < n; i++) {
            int idx = bs(nums , nums[i][1]);
            ans[hash[nums[i][0]]] = (idx == n) ? -1 : hash[nums[idx][0]];
        }
        
        return ans;
    }
};