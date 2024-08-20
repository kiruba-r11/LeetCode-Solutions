class Solution {
public:
    bool p_check(map <char , int> &hash) {
    
        for(auto i: hash) {
            if(i.second > 0) return false;
        }
        
        return true;
    }
    
    bool f_check(map <char , int> &hash , int t_size , int window) {
        
        for(auto i: hash) {
            if(i.second < 0) return true;
        }
        
        if(t_size < window) return true;
        
        return false;
    }
    
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        if(n < m) return "";
        // if(n == m) {
        //     if(s == t) return s;
        //     return "";
        // }
        
        int i = 0 , j = 0;
        int start = -1 , end = -1;
        int ans = n;
        map <char , int> hash;
        
        for(auto i: t) {
            hash[i]++;
        }
        
        while(j < n) {
            if(hash.find(s[j]) != hash.end()) hash[s[j]]--;
            while(f_check(hash , m , j - i + 1)) {
                if(hash.find(s[i]) != hash.end()) {
                    if(hash[s[i]] >= 0) {
                        break;
                    }
                    hash[s[i]]++;
                }
                i++;
            }
            if(p_check(hash)) {
                if(ans >= (j - i + 1)) {
                    ans = j - i + 1;
                    start = i;
                    end = j;
                }
            }
            j++;
        }
        
        string r = "";
        if(start != -1 && end != -1)
            for(int i = start; i <= end; i++) r.push_back(s[i]);
        
        return r;
    }
};