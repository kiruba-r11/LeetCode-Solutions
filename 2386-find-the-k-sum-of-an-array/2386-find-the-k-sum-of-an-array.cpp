class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        
        long long sum = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) sum += nums[i];
            nums[i] = abs(nums[i]);
        }
        
        sort(nums.begin() , nums.end());
        
        priority_queue <pair <long long , int>> pq;
        vector <long long> ans;
        
        ans.push_back(sum);
        pq.push({sum - nums[0] , 0});
        
        while(ans.size() < k) {
            long long cursum = pq.top().first;
            int idx = pq.top().second;
            
            pq.pop();
            
            ans.push_back(cursum);
            
            if(idx < n - 1) {
                pq.push({cursum + nums[idx] - nums[idx + 1] , idx + 1});
                pq.push({cursum - nums[idx + 1] , idx + 1});
            }
        }
        
        return ans[k - 1];
    }
};