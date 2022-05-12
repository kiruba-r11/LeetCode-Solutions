class Solution {
public:
    int minimumDeletions(string s) {
        stack <char> st;
        int ans = 0 , n = s.size();
        
        for(int i = n - 1; i >= 0; i--) {
            if(!st.empty() && (st.top() == 'a' && s[i] == 'b')) {
                ans++;
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        
        return ans;
    }
};