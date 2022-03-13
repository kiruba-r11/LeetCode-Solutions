class Solution {
public:
    bool isValid(string s) {
        /*
        
        O(N) time and space complexity
        Idea -> Stack
        
        */
        
        stack <char> st;
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else {
                if(st.size() == 0) return false;
                
                char ch = st.top();
                st.pop();
                
                if((s[i] == ')' && ch == '(') || (s[i] == ']' && ch == '[') || (s[i] == '}' && ch == '{'))
                    continue;
                else
                    return false;
            }
        }
        
        return st.size() == 0;
    }
};