class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int i = 0 , j = 0;
        int ans = n + 1 , cnt = 0;
        string res = "";
        
        while(j < n) {
            cnt += s[j] - '0';
            while(cnt >= k) {
                if(s[i] == '1' && cnt == k) break;
                cnt -= s[i] - '0';
                i++;
            }
            if(cnt == k) {
                if(ans > j - i + 1) {
                    ans = j - i + 1;
                    res = s.substr(i , ans);
                } else if(ans == j - i + 1) {
                    string temp = s.substr(i , ans);
                    if(temp < res) res = temp;
                }
            }
            j++;
        }
        
        return res;
        
    }
};