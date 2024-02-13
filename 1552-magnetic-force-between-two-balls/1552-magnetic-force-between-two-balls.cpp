class Solution {
public:
    bool distance(vector <int> &nums , int k , int mid) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            int j = i + 1;
            while(j < n && (nums[j] - nums[i]) < mid) {
                j++;
            }
            cnt++;
            i = j - 1;
        }
        if(cnt >= k) return true;
        return false;
    }
    
    int maxDistance(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        int low = 1 , high = nums[n - 1];
        int ans = low;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(distance(nums , k , mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};