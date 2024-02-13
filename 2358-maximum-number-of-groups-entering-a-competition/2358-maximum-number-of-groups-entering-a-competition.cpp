class Solution {
public:
    int split(int cnt) {
        
        int low = 1 , high = 8 * cnt + 1;
        int ans = high;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            long long sqrt = mid * 1LL * mid;
            if(sqrt <= 8 * cnt + 1) {
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return (ans - 1) / 2;
    }
    
    int maximumGroups(vector<int>& grades) {
        return split(grades.size());
    }
};