class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size() , len = 0;
        vector <int> dp(n , 1);
        vector <int> hash(n);
        
        int idx = -1;
        for(int i = 0; i < n; i++) {
            hash[i] = i;
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {
                    if(dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        hash[i] = j;
                    }
                }
            }
            
            if(len <= dp[i]) {
                len = dp[i];
                idx = i;
            }
        }
        
        while(idx != hash[idx]) {
            cout << nums[idx] << ' ';
            idx = hash[idx];
        }
        cout << nums[idx] << " " << endl;
        return len;
    }
};