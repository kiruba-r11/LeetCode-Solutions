class Solution {
public:
    unordered_map <string , bool> hash;
    int ans = INT_MAX;
    
    bool noleadzero(string &s) {
        return s[0] != '0';
    }
    
    bool ispowerfive(string &s) {
        unordered_map <string , bool> store;    
        
        store["1"] = true;
        store["101"] = true;
        store["11001"] = true;
        store["1111101"] = true;
        store["1001110001"] = true;
        store["110000110101"] = true;
        store["11110100001001"] = true;
        
        return store.find(s) != store.end();
    }
    
    int cnt = 0;
    void solve(string &s , int idx) {
        
        if(s.size() == idx) {
            ans = min(ans , cnt);
            return;
        }
        
        string prefix = "";
        for(int i = idx; i < s.size(); i++) {
            prefix += s[i];
            if(noleadzero(prefix) && ispowerfive(prefix)) {
                hash[prefix] = true;
                cnt++;
                solve(s , i + 1);
                cnt--;
                hash.erase(prefix);
            }
        }
        
    }
    int minimumBeautifulSubstrings(string s) {
        solve(s , 0);
        return ans == INT_MAX ? -1 : ans;
    }
};