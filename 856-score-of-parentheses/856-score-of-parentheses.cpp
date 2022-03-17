class Solution {
public:
    int scoreOfParentheses(string s) {
        
        /*
        
        O(N) time and space complexity
        
        */
        
        stack <pair <char , int>> st;
        int n = s.size() , ans = 0;
        
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                st.push({s[i] , 0});
            } else {
                int val = st.top().second;
                st.pop();
                
                if(val == 0) val++;
                else val *= 2;
                
                
                if(!st.empty()) {
                    int nextVal = st.top().second;
                    st.pop();
                    nextVal += val;
                    st.push({'(' , nextVal});
                } else {
                    ans += val;
                }
            }
        }
        
        return ans;
    }
};