class Solution {
public:
    int compress(vector<char>& chars) {
        vector <char> ans;
        int len = 0;
        for(int i = 0; i < chars.size(); i++) {
            int j = i + 1;
            while(j < chars.size() && chars[i] == chars[j]) j++;
            int cnt = j - i;
            
            len++;
            ans.push_back(chars[i]);
            if(cnt > 1) {
                vector <char> temp;
                while(cnt > 0) {
                    char val = cnt % 10 + '0';
                    temp.push_back(val);
                    cnt /= 10;
                    len++;
                }
                reverse(temp.begin() , temp.end());
                for(auto k: temp) {
                    ans.push_back(k);
                }
            }
            i = j - 1;
        }
        
        for(int i = 0; i < ans.size(); i++) {
            chars[i] = ans[i];
        }
        
        return len;
    }
};