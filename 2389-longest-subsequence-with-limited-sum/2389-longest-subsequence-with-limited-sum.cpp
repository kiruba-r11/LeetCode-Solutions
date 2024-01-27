class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();
        
        vector <int> ans(m , -1);
        vector <int> prefix(n);
        
        sort(nums.begin() , nums.end());
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(prefix[j] > queries[i]) {
                    ans[i] = j;
                    break;
                }
            }
            if(ans[i] == -1) ans[i] = n;
        }
        
        return ans;
    }
};