class Solution {
public:
    bool slide(vector <int> &nums , int allow , int k) {
        int n = nums.size();
        int i = 0 , j = 0;
        
        while(j < n) {
            int window = j - i + 1;
            if(window <= k) {
                if(nums[j] == 0) allow--;
                if(window == k) {
                    if(allow >= 0) return true;
                }
                j++;
            } else {
                if(nums[i] == 0) allow++;
                i++;
            }
        }
        
        return false;
    }
    
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0 , high = n;
        int ans = low;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            bool check = slide(nums , k , mid);
            if(check) {
                ans = mid;
                low = mid + 1; // increases the size
            } else {
                high = mid - 1; // decreases the size
            }
        }
        return ans;
    }
};