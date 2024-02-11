class Solution {
public:
    int bs(vector <int> &nums , int key) {
        int low = 0 , high = nums.size() - 1;
        int ans = nums.size();
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] >= key) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        int count = 0;
        for(int i = 0; i < n; i++) {
            int j = bs(nums , target - nums[i]) - 1;
            if(j > i) count += j - i;
        }
        
        return count;
    }
};