class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        
        int n = nums.size();
        int change = INT_MAX;
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            int j = i + 1;
            int k = n - 1;
            int sum = nums[i];
            
            while(j < k) {
                int sum1 = sum + nums[j] + nums[k];
                if(sum1 == target) return sum1;
                if(sum1 < target) j++;
                else k--;
                
                int diff = abs(sum1 - target);
                if(diff < change) {
                    change = diff;
                    ans = sum1;
                }
            }
        }
        
        return ans;
    }
};

