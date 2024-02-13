class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0 , high = n - 1;
        if(n == 1) return nums[0];
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(mid == 0) {
                if(nums[mid] == nums[mid + 1]) low = mid + 1;
                else return nums[mid];
            } else if(mid == n - 1) {
                if(nums[mid] == nums[mid - 1]) high = mid - 1;
                else return nums[mid];
            } else {
                if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) return nums[mid];
                if(mid & 1) {
                    if(nums[mid] == nums[mid - 1]) low = mid + 1;
                    else high = mid - 1;
                } else {
                    if(nums[mid] == nums[mid + 1]) low = mid + 1;
                    else high = mid - 1;
                }
            }
        }
        
        return -1;
    }
};

// 1 -> 0 , 1
// 2 -> 2 , 3
// 3 -> 4 , 5
// 4 -> 6 , 7
    
// idx is odd, idx is even
// idx even -> idx / 2 elements on the left, 
// so a[idx] == a[idx + 1] => go right, but if not, go left
// idx odd -> idx / 2 + 1 elements on the left, 
// so a[idx] == a[idx - 1] => go right, but if not, go left