class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        int n = s.size() , m = sub.size();
        map <char , map <char , bool>> hash;
        for(auto i: mappings) {
            hash[i[0]][i[1]] = true;
        }
        
        for(int i = 0; i <= n - m; i++) {
            bool check = true;
            for(int j = 0; j < m; j++) {
                if(s[i + j] == sub[j]) continue;
                else if(hash.find(sub[j]) != hash.end() && hash[sub[j]][s[i + j]]) continue;
                else {
                    check = false;
                    break;
                }
            }
            if(check) return true;
        }
        
        return false;
    }
};