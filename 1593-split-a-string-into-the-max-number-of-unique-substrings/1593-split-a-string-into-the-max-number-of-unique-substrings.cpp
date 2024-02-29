class Solution {
public:
    map <string , bool> hash;
    int ans = 0;
    
    void solve(string &s , int idx) {
        if(idx == s.size()) {
            ans = max(ans , (int)hash.size());
            return;
        }
        
        string prefix = "";
        for(int i = idx; i < s.size(); i++) {
            prefix += s[i];
            if(hash.find(prefix) == hash.end()) {
                hash[prefix] = true;
                solve(s , i + 1);
                hash.erase(prefix);
            }
        }
    }
    
    int maxUniqueSplit(string s) {
        solve(s , 0);
        return ans;
    }
};