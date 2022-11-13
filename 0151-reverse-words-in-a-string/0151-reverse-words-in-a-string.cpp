class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        for(int i = s.size() - 1; i >= 0;) {
            while(i >= 0 && s[i] == ' ') i--;
            int j = i;
            while(j >= 0 && s[j] != ' ') j--;
            bool check = false;
            for(int k = j + 1; k <= i; k++) {
                ans += s[k];
                check = true;
            }
            if(check)
                ans += " ";
            i = j;
        }
        ans.pop_back();
        return ans;
    }
};