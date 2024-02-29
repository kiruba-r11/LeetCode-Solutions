class Solution {
public:
    vector <string> ans;
    vector <string> cur;
    
    bool noleadzero(string &s) {
        if(s[0] != '0') return true;
        if(s.size() == 1) return true;
        return false;
    }
    
    bool inrange(string &s) {
        int num = stoi(s);
        if(num >= 0 && num <= 255) return true;
        return false;
    }
    
    void solve(string &s , int idx) {
        if(cur.size() > 4) return;
        if(s.size() == idx) {
            string temp = "";
            for(int x = 0; x < cur.size(); x++) {
                if(x == 0) temp += cur[x];
                else {
                    temp += ".";
                    temp += cur[x];
                }
            }
            if(temp.size() != s.size() + 3) return;
            ans.push_back(temp);
            return;
        }
        
        string prefix = "";
        for(int i = idx; i < s.size(); i++) {
            if(prefix.size() > 3) break;
            prefix += s[i];
            
            if(noleadzero(prefix) && inrange(prefix)) {
                cur.push_back(prefix);
                solve(s , i + 1);
                cur.pop_back();
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        solve(s , 0);
        return ans;
    }
};