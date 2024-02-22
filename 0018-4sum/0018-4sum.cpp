class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        
        int n = nums.size();
        vector <vector <int>> ans;
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int start = j + 1;
                int end = n - 1;
                while(start < end) {
                    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[start] + (long long)nums[end];
                    
                    int ts = start;
                    while(ts < n && nums[ts] == nums[start]) ts++;
                    
                    int te = end;
                    while(te >= 0 && nums[te] == nums[end]) te--;
                    
                    if(sum == target) {
                        ans.push_back({nums[i] , nums[j] , nums[start] , nums[end]});
                        start = ts;
                        end = te;
                    } else if(sum < target) {
                        start = ts;
                    } else {
                        end = te;
                    }
                }
                int tj = j;
                while(tj < n && nums[tj] == nums[j]) tj++;
                j = tj - 1;
            }
            int ti = i;
            while(ti < n && nums[ti] == nums[i]) ti++;
            i = ti - 1;
        }
        
        return ans;
    }
};