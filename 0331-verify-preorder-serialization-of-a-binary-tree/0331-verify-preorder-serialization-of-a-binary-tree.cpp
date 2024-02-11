class Solution {
public:
    void print(stack <pair <string , int>> s) {
        while(!s.empty()) {
            cout << s.top().first << " " << s.top().second << endl;
            s.pop();
        }
        cout << endl << endl;
    }
    
    bool isValidSerialization(string preorder) {
        if(preorder == "#") return true;
        
        stack <pair <string , int>> st;
        int n = preorder.size();
        
        bool root = false;
        
        for(int i = 0; i < n; i++) {
            string num = "";
            int j = i;
            while(j < n && preorder[j] != ',') {
                num.push_back(preorder[j]);
                j++;
            }
            i = j;
            if(num == "#") {
                if(st.empty()) return false;
                while(!st.empty() && st.top().second == 2) {
                    st.pop();
                }
                
                if(!st.empty()) {
                    string top = st.top().first;
                    int state = st.top().second;
                    st.pop();
                    
                    st.push({top , state + 1});
                }
            } else {
                if(st.empty()) {
                    if(!root) root = true;
                    else return false;
                }
                st.push({num , 1});
            }
        }

        return st.empty();
    }
};

// states for stack appoach
// insert node with 1 and move left
// if 1 -> change to 2, go right
// if 2 -> delete






