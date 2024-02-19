class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        
        int s = 0 , e = n - 1;
        while(s < e) {
            int sum = nums[s] + nums[e];
            if(sum == 0) return nums[e];
            if(sum < 0) s++;
            else e--;
        }
        return -1;
    }
};