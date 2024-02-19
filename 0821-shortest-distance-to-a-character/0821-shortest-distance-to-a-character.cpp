class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        int left = -1;
        int right = -1;
        
        vector <int> ans(n , INT_MAX);
        
        // forward
        for(int i = 0; i < n; i++) {
            if(s[i] == c) left = i;
            ans[i] = left == -1 ? INT_MAX : i - left;
        }
        
        // backward
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == c) right = i;
            ans[i] = right == -1 ? ans[i] : min(ans[i] , right - i);
        }
        
        return ans;
    }
};