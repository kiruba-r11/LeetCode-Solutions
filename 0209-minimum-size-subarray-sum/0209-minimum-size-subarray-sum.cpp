class Solution {
public:
    bool slide(vector <int> &nums , int target , int k) {
    
        int n = nums.size();
        int i = 0 , j = 0 , sum = 0;
        
        while(j < n) {
            int window = j - i + 1;
            if(window <= k) {
                sum += nums[j];
                
                if(window == k) {
                    if(sum >= target) return true;
                }
                
                j++;
            } else {
                sum -= nums[i];
                i++;
            }
        }
        
        return false;
    }
    
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int low = 0 , high = n , ans = 0;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            bool check = slide(nums , target , mid);
            if(check) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};