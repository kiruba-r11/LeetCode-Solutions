class Solution {
public:
    int bs(vector <int> &nums , int low , int high , int val , int key) {
        int ans = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(val + key <= nums[mid]) {
                if(val + key == nums[mid]) ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }   
        return ans;
    }
    
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        int cnt = 0;        
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int j = i;
            int s = i;
            while(j < n && nums[j] == nums[i]) j++;
            i = j - 1;
            if(k == 0) {
                if(i != s) cnt++;
            } else {
                int idx = bs(nums , i + 1 , n - 1 , nums[i] , k);
                if(idx != -1) cnt++;
            }
        }
        
        return cnt;
    }
};