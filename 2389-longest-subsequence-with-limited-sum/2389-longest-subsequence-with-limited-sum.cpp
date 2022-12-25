class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& q) {
        int n = nums.size() , m = q.size();
        vector <int> ans(m);
        sort(nums.begin() , nums.end());
        for(int i = 0; i < m; i++) {
            int sum = 0 , len = 0;
            for(int j = 0; j < n; j++) {
                if(sum + nums[j] <= q[i]) sum += nums[j] , len++;
                else break;
            }
            ans[i] = len;
        }
        return ans;
    }
};