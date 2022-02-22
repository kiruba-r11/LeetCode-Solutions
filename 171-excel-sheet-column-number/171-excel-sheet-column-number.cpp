class Solution {
public:
    int titleToNumber(string columnTitle) {
        
        /*
        
        O(N) time and O(1) space complexity
        
        */
        
        int n = columnTitle.size();
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            ans *= 26;
            ans += (columnTitle[i] - 64);
        }
        
        return ans;
    }
};