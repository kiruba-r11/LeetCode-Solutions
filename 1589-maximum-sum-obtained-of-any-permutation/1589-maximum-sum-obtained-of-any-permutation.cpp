class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        int m = requests.size();
        vector <int> prefix(n + 1);
        
        for(int i = 0; i < m; i++) {
            int start = requests[i][0];
            int end = requests[i][1];
            prefix[start]++;
            prefix[end + 1]--;
        }
        
        for(int i = 1; i <= n; i++) {
            prefix[i] += prefix[i - 1];
        }
        
        sort(nums.rbegin() , nums.rend());
        sort(prefix.rbegin() , prefix.rend());
        int mod = 1e9 + 7;
        long long ans = 0;
        
        for(int i = 0; i < n; i++) {
            ans = ((ans % mod) + (prefix[i] * 1LL * nums[i]) % mod) % mod;
        }
        
        return (int)ans;
    }
};