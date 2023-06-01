class Solution {
public:
    bool slide(vector <int> &nums , int k , int flip) {
        
        int n = nums.size();
        int i = 0 , j = 0;
        
        while(j < n) {
            int window = j - i + 1;
            if(window <= k) {
                if(nums[j] == 0) flip--;
                
                if(window == k) {
                    if(flip >= 0) return true;
                }
                
                j++;
            } else {
                if(nums[i] == 0) flip++;
                i++;
            }
        }
        
        return false;
    }
    
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0 , high = n , ans = 0;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            bool check = slide(nums , mid , k);
            if(check) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};