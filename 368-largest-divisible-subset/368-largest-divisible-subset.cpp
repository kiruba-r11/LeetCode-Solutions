class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        
        int n = nums.size();
        vector <int> dp(n , 1) , hash(n);
        
        int idx = -1 , len = 1;
        for(int i = 0; i < n; i++) {
            hash[i] = i;
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0) {
                    if(dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        hash[i] = j;
                    }
                } 
            }
            
            if(dp[i] >= len) {
                len = dp[i];
                idx = i;
            }
        }
        
        vector <int> ans;
        while(idx != hash[idx]) {
            ans.push_back(nums[idx]);
            idx = hash[idx];
        }
        if(idx == hash[idx]) ans.push_back(nums[idx]);
        reverse(ans.begin() , ans.end());
        return ans;
    }
};