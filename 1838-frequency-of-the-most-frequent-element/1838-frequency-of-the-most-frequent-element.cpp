class Solution {
public:
    bool condition(vector <int> &nums , int k , int val) {
    
        int n = nums.size();
        int i = 0 , j = 0;
        long long sum = 0;
        
        while(j < n) {
            int window = j - i + 1;
            if(window <= k) {
                sum += nums[j];
                
                if(window == k) {
                    int last = nums[j];
                    int cnt = k - 1;
                    if((sum - last + val) >= cnt * 1LL * last) return true;
                }
                
                j++;
            } else {
                sum -= nums[i];
                i++;
            }
        }
        
        return false;
    }
    
    
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        
        int low = 1 , high = n;
        int ans = 0;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(condition(nums , mid , k)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};