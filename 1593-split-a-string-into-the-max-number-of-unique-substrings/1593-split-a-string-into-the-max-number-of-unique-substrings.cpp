class Solution {
public:
    int ans = 0;
    void solve(string &s , int start , map <string , int> &hash) {
        int n = s.size();
        
        if(start == n) {
            ans = max(ans , (int)hash.size());
            return;
        }
        
        string prefix = "";
        for(int i = start; i < n; i++) {
            prefix.push_back(s[i]);
            if(hash.find(prefix) == hash.end()) {
                hash[prefix] = 1;
                solve(s , i + 1 , hash);
                hash.erase(prefix);
            }
        }
    }
    
    int maxUniqueSplit(string s) {
        map <string , int> hash;
        solve(s , 0 , hash);
        return ans;
    }
};