class Solution {
public:
    bool isSub(string &s , string &str , int k) {
        int n = s.size();
        int m = str.size();
        for(int i = 0 , j = 0; i < n; i++) {
            if(s[i] == str[j]) {
                j++;
                if(j == m) {
                    k--;
                    j = 0;
                }
            } 
        }

        return k <= 0;
    }
    
    string longestSubsequenceRepeatedK(string s, int k) {
        string ans = "";
        
        queue <string> q;
        q.push("");
        
        while(!q.empty()) {
            int count = q.size();
            for(int i = 0; i < count; i++) {
                string str = q.front();
                q.pop();
                
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    string newstr = str;
                    newstr.push_back(ch);
                    cout << newstr << endl;
                    if(isSub(s , newstr , k)) {
                        q.push(newstr);
                        ans = newstr;
                    }
                }
            }
        }
        
        return ans;
    }
};