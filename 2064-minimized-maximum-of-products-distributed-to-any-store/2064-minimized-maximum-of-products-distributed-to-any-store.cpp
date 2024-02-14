class Solution {
public:
    bool condition(vector <int> &nums , int val , int items) {
    
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            cnt += nums[i] / val + (nums[i] % val != 0);
        }
        return cnt <= items;
    }
    

    int minimizedMaximum(int k, vector<int>& quantities) {
        int n = quantities.size();
        int low = 1 , high = quantities[0];
        for(int i = 1; i < n; i++) {
            high = max(high , quantities[i]);
        }
        int ans = high;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(condition(quantities , mid , k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};