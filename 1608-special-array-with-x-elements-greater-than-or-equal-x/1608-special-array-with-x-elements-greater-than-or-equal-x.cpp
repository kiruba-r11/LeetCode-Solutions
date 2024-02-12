class Solution {
public:
    int search(vector <int> &nums , int key) {
        int n = nums.size();
        int low = 0 , high = n - 1;
        int ans = n;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] >= key) {
                ans = mid;
                high = mid - 1;
            } else low = mid + 1;
        }
        return n - ans;
    }

    int specialArray(vector<int>& nums) {
        int low = 1 , high = 1000;
        sort(nums.begin() , nums.end());
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int cnt = search(nums , mid);
            if(cnt == mid) return mid;
            if(cnt < mid) high = mid - 1;
            else low = mid + 1;
        }
        
        return -1;
    }
};