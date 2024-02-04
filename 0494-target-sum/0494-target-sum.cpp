class Solution {
public:
    int cnt = 0;
    void sum(vector <int> &nums , int target , int i , int &cur) {
        
        if(i == nums.size()) {
            if(cur == target) cnt++;
            return;
        }
    
        cur += nums[i];
        sum(nums , target , i + 1 , cur);
        cur -= nums[i];
        
        cur -= nums[i];
        sum(nums , target , i + 1 , cur);
        cur += nums[i];
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int cur = 0;
        sum(nums , target , 0 , cur);
        return cnt;
    }
};