class Solution {
public:
    string findLongestWord(string s, vector<string>& dic) {
        sort(dic.begin() , dic.end());
        
        int n = s.size() , m = dic.size();
        int len = 0;
        
        string ans = "";
        
        for(int i = 0; i < m; i++) {
            int si = 0;
            int di = 0;
            int mm = dic[i].size();
            
            while(si < n && di < mm) {
                if(s[si] == dic[i][di]) {
                    si++;
                    di++;
                } else {
                    si++;
                }
            }
            
            if(di == mm) {
                if(mm > len) {
                    len = mm;
                    ans = dic[i];
                }
            }
        }
        
        return ans;
    }
};