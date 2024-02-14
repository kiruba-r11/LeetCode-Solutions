class Solution {
public:
    bool condition(string &s , string &t , int maxCost , int k) {
    
        int n = s.size();
        int i = 0 , j = 0;
        int cost = 0;
        
        while(j < n) {
            int window = j - i + 1;
            if(window <= k) {
                cost += abs(s[j] - t[j]);
                
                if(window == k) {
                    if(cost <= maxCost) return true;
                }
                
                j++;
                
            } else {
                cost -= abs(s[i] - t[i]);
                i++;
            }
        }
        
        return false;
    }
    
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int low = 0 , high = n;
        int ans = low;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(condition(s , t , maxCost , mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};