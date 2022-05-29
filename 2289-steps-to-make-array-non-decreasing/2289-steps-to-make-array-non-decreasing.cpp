class Solution {
public:
    int totalSteps(vector<int>& nums) {
        
        int n = nums.size() , res = 0;
        stack <int> s;
        vector <int> dp(n);
        
        for(int i = n - 1; i >= 0; i--) {
            while(!s.empty() && nums[i] > nums[s.top()]) {
                dp[i] = max(dp[i] + 1 , dp[s.top()]);
                s.pop();
                
                res = max(res , dp[i]);
            }
            s.push(i);
        }
        
        return res;
    }
};