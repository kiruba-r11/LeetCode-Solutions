class Solution {
public:
    string minimizeStringValue(string s) {
        int n = s.size();

        vector <int> hash(26);
        vector <char> insert;
        
        for(int i = 0; i < n; i++) {
            if(s[i] != '?') {
                hash[s[i] - 'a']++;
            }
        }
        
        int idx = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '?') {
                char selected = '-';
                int contribution = 1e5;
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    int cnt = hash[ch - 'a'];
                    
                    int cur = cnt;
                    if(cur < contribution) {
                        selected = ch;
                        contribution = cur;
                    }
                }
                insert.push_back(selected);
                hash[selected - 'a']++;
            } 
        }
           
        sort(insert.begin() , insert.end());
        int m = insert.size();
        for(int i = n - 1 , idx = m - 1; idx >= 0; i--) {
            if(s[i] == '?') s[i] = insert[idx--];
        }
        
        return s;
    }
};