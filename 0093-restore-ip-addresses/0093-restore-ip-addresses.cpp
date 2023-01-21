class Solution {
public:
    bool noLeading(string &s) {
    
        if(s[0] != '0' || s == "0") return true;
        return false;
    }
    
    void solve(string s , int index , string ip , vector <string> &ips , string cur , int cnt) {
        
        if(index == s.size()) {
            if(cnt == 4 && (ip.size() == s.size() + 4)) {
                ip.pop_back();
                ips.push_back(ip);
            }
            return;
        }
        

        cur += s[index];
        solve(s , index + 1 , ip , ips , cur , cnt);
        
        if((cur.size() && cur.size() <= 3) && (stoi(cur) <= 255) && (noLeading(cur)) && cnt <= 3) {
            ip += cur;
            ip += ".";
            solve(s , index + 1 , ip , ips , "" , cnt + 1);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        string ip = "" , cur = "";
        vector <string> ips;
        int cnt = 0;
        solve(s , 0 , ip , ips , cur , cnt);
        return ips;
    }
};