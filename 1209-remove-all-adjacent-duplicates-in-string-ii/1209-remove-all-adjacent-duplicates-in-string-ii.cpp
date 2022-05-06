class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack <pair <char , int>> st;

        for(auto i: s) {
            if(st.empty()) {
                st.push({i , 1});
            } else {
                pair <char , int> top = st.top();
                st.pop();
                if(top.first == i) {
                    if(top.second != k - 1)
                        st.push({i , top.second + 1});
                }
                else {
                    st.push(top);
                    st.push({i , 1});
                }
            }
        }
        
        string ans = "";
        while(!st.empty()) {
            while(st.top().second--)
                ans += st.top().first;
            st.pop();
        }
        
        reverse(ans.begin() , ans.end());
        
        return ans;
    }
};