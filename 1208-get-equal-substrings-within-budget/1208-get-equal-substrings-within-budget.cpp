class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int i = 0 , j = 0 , ans = 0;
        
        while(j < n) {
            int cost = abs(s[j] - t[j]);
            if(cost <= maxCost) {
                ans = max(ans , j - i + 1);
                maxCost -= cost;
                j++;
            } else {
                while(maxCost < cost) {
                    maxCost += abs(s[i] - t[i]);
                    i++;
                }
            }
        }
        
        return ans;
    }
};