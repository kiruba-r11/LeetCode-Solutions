class Solution {
public:
    bool condition(int n , int index , int maxSum , int val) {
                                                              
        int cnt_left = index;
        int cnt_right = n - index - 1;
        long long sum = 0;
        
        if(cnt_left >= val - 1) {
            sum += val * 1LL * (val - 1) / 2;
            sum += cnt_left - (val - 1);
        } else {
            sum += val * 1LL * (val - 1) / 2;
            int del = (val - 1) - cnt_left;
            sum -= del * 1LL * (del + 1) / 2;
        }
        
        if(cnt_right >= val - 1) {
            sum += val * 1LL * (val - 1) / 2;
            sum += cnt_right - (val - 1);
        } else {
            sum += val * 1LL * (val - 1) / 2;
            int del = (val - 1) - cnt_right;
            sum -= del * 1LL * (del + 1) / 2;
        }
        
        return (sum + val) <= maxSum;
    }
    
    int maxValue(int n, int index, int maxSum) {
        int low = 1 , high = maxSum;
        int ans = low;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(condition(n , index , maxSum , mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};

// n
// 1s + sum(1..n -1) + n + sum(n-1..1) + 1s