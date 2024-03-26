class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector <long long> prefix(n);
        vector <long long> suffix(n);
        
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        
        suffix[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + nums[i];
        }
        
        int cnt = 0;
        for(int i = 0; i < n - 1; i++) {
            long long first = prefix[i];
            long long last = suffix[i + 1];
            if(first >= last) cnt++;
        }
        
        return cnt;
    }
};