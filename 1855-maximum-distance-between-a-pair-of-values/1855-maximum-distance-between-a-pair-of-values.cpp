class Solution {
public:
    int bs(vector <int> &nums , int low , int high , int key) {
    
        int ans = low;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(key <= nums[mid]) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
    
    
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() , m = nums2.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int j = bs(nums2 , i , m - 1 , nums1[i]);
            ans = max(ans , j - i);
        }
        return ans;
    }
};