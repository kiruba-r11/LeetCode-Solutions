class Solution {
public:
    int find(vector <int> &nums) {
        int n = nums.size() , low = 0 , high = n - 1;
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(nums[mid]>nums[high]){
                low = mid+1;
            }
            else
                high = mid;
        }
        
        return nums[low];
    }
    
    int findMin(vector<int>& nums) {
        return find(nums);
    }
};