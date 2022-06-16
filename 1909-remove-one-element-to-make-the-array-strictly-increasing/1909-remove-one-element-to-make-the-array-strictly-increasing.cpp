class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            bool check1 = true , check2 = true;
            
            for(int j = 1; j < i; j++) {
                if(nums[j] <= nums[j - 1]) {
                    check1 = false;
                    break;
                }
            }
            
            for(int j = i + 2; j < n; j++) {
                if(nums[j] <= nums[j - 1]) {
                    check2 = false;
                    break;
                }
            }
            
            if(check1 && check2) {
                if(i == 0 || i == n - 1 || nums[i + 1] > nums[i - 1]) return true;
            }
        }
        
        return false;
    }
};