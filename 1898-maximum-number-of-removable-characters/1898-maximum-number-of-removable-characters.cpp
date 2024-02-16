class Solution {
public:
    bool condition(string s , string &p , vector <int> &nums , int k) {
    
        for(int i = 0; i < k; i++) {
            s[nums[i]] = '-';
        }
        
        int i = 0 , j = 0;
        int n = s.size() , m = p.size();
        
        while(i < n && j < m) {
            if(s[i] == p[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }

        return j == m;
    }
    
    int maximumRemovals(string s, string p, vector<int>& nums) {
        int n = nums.size();
        if(condition(s , p , nums , n)) return n;
        
        int low = 0 , high = n - 1;
        int ans = 0;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(condition(s , p , nums , mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};