class Solution {
public:
    int mask = 0;
    bool dfs(vector <int> &nums , int idx , vector <int> &sq , int sum , int start) {
    
        if(idx == nums.size()) {
            return mask == ((1 << (sq.size())) - 1);
        }
        
        for(int i = start; i < sq.size(); i++) {
            // pruning condition
            if(sq[i] + nums[idx] <= sum) {
                sq[i] += nums[idx];
                if(sq[i] == sum) mask = mask ^ (1 << i) , start = i + 1;
                if(dfs(nums , idx + 1 , sq , sum , start)) return true;
                if(sq[i] == sum) mask = mask ^ (1 << i);
                sq[i] -= nums[idx];
            }
        }
        
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        vector <int> sq(k);
        
        int sum = 0;
        int n = nums.size();
        
        // pruning
        sort(nums.rbegin() , nums.rend());
        for(int i = 0; i < n; i++) sum += nums[i];
        
        if(sum % k) return false;
        if(nums[0] > sum / k) return false;
        // ---
        
        return dfs(nums , 0 , sq , sum / k , 0);
    }
};