class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        /*
        
        O(N) time and space complexity
        Idea -> Monotonic Stack
        
        Intuition:
            1. Maintain a stack of elements such that they are in increasing order
            2. Everytime this monotonicity fails, the stack can be invalid till some point, if and only if:
                2.1. The current character is lesser than the top of the stack
                2.2. The current character has not been picked (present in stack) already 
                2.3. The character at the top of the stack has the occurance in the later part of the string (that is from index '(i + 1)' for the current index 'i')
         
        */
        
        int n = s.size();
        
        vector <int> hash(26 , 0) , picked(26 , 0);
        stack <char> st;
        
        for(int i = 0; i < n; i++) {
            hash[s[i] - 97]++;
        }
        
        for(int i = 0; i < n; i++) {
            while(!st.empty()) {
                char ch = st.top();
                if(ch > s[i] && hash[ch - 97] >= 1 && picked[s[i] - 97] == 0) {
                    st.pop();
                    picked[ch - 97] = 0;
                } else break;
            }
            
            if(picked[s[i] - 97] == 0) st.push(s[i]);
            
            picked[s[i] - 97] = 1;
            hash[s[i] - 97]--;
            
        }
        
        string ans = "";
        while(!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        
        return ans;
    }
};