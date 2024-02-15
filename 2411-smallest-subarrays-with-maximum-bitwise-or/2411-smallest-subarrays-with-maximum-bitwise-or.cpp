class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        int max_or = 0;
        
        vector <vector <int>> bits(n , vector <int> (32));
        for(int i = n - 1; i >= 0; i--) {
            max_or |= nums[i];
            for(int k = 0; k < 32; k++) {
                bits[i][k] = max_or & (1 << k);
            }
        }
        
        vector <long long> req(32 , 0);
        vector <int> ans(n);
        
        int start = 0 , cnt = 0;
        
        for(int i = n - 1; i >= 0; i--) {
            if(nums[i] == 0) {
                cnt++;
                ans[i] = 1;
            }
            else break;
        }
        
        for(int i = 0 , start = 0; start < n - cnt;) {
            bool check = true;
            for(int k = 0; k < 32; k++) {
                if(req[k] < bits[start][k]) {
                    check = false;
                    break;
                }
            }
            if(check) {
                ans[start] = i - start;
                
                for(int k = 0; k < 32; k++) {
                    req[k] -= nums[start] & (1 << k);
                }
                start++;
            } else {
                if(i < n) {
                    for(int k = 0; k < 32; k++) {
                        req[k] += nums[i] & (1 << k);
                    }
                    i++;
                }
            }
        }
        
        return ans;
    }
};


