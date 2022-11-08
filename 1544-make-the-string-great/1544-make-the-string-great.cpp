class Solution {
public:
    string makeGood(string s) {
        string ans = "";
        stack <char> st;
        
        for(auto i: s) {
            if(st.size() == 0) {
                st.push(i);
            } else {
                if(abs(st.top() - i) == 32)
                    st.pop();
                else
                    st.push(i);
            }
        }
                   
        while(!st.empty()) {
            char x = st.top();
            string r(1 , x);
            st.pop();
            ans = r + ans;
        }
       return ans;
    }
};