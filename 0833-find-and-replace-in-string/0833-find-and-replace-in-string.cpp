class Solution {
public:
    bool isPossible(string s , int idx , string src) {
        int i = 0;
        int m = s.size();
        int n = src.size();
        while(i < n && idx < m) {
            if(s[idx] != src[i]) return false;
            i++;
            idx++;
        }
        
        if(i < n) return false;
        return true;
    }
    
    string findReplaceString(string s, vector<int>& idx, vector<string>& src, vector<string>& tar) {
        
        int n = s.size();
        int m = idx.size();
        int i = 0 , j = 0;
        string ans = "";
        
        map <int , pair <string , string>> hash;
        for(int k = 0; k < m; k++) {
            hash[idx[k]] = {src[k] , tar[k]};
        }

        vector <pair <int , pair <string , string>>> vp;
        for(auto i: hash) {
            vp.push_back({i.first , {i.second.first , i.second.second}});
        }
        
        sort(vp.begin() , vp.end());
        
        for(int k = 0; k < vp.size(); k++) {
            idx[k] = vp[k].first;
            src[k] = vp[k].second.first;
            tar[k] = vp[k].second.second;
        }
        
        for(; i < n && j < vp.size(); i++) {
            if(i < idx[j]) {
                ans += s[i];
            } else if(i == idx[j]) {
                bool check = isPossible(s , i , src[j]);
                if(check) {
                    ans += tar[j];
                    i += src[j].size() - 1;
                } else {
                    ans += s[i];
                }
                j++;
            }
        }
        
        while(i < n) {
            ans += s[i];
            i++;
        }
        return ans;
    }
};