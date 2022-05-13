class Solution {
public:
    vector <int> solve(vector <int> &nums) {
        
        int n = nums.size() , maxi = 0;
        
        vector <int> dp(n , 1) , hash(n);
        
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
            if(dp[maxi] < dp[i]) {  
                maxi = i;
            }
        }
        vector <int> ans;
        
        int prev = -1;
        while(maxi != prev) {
            ans.push_back(nums[maxi]);
            prev = maxi;
            maxi = hash[maxi];
        }
        reverse(ans.begin() , ans.end());
        
        return ans;
    }
    
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        sort(nums.begin() , nums.end());
        return solve(nums);
    }
};