class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        map <char , vector <int>> hash; //char -> {max_length, max_length_cnt, second_max}
        
        for(int i = 0; i < n; i++) {
            int j = i;
            while(j < n && s[i] == s[j]) j++;
            int cnt = j - i;
            i = j - 1;
            
            vector <int> info = hash[s[i]];
            if(info.size() == 0) {
                info.resize(3);
                info[0] = cnt;
                info[1] = 1;
                info[2] = 0;
            } else {
                if(cnt == info[0]) {
                    info[1]++;
                } else if(cnt > info[0]) {
                    info[2] = max(info[2] , info[0]);
                    info[0] = cnt;
                    info[1] = 1;
                } else {
                    if(cnt > info[2]) info[2] = cnt;
                }
            }
            hash[s[i]] = info;
        }
        
        int ans = -1;
        for(auto i: hash) {
            vector <int> info = i.second;
            if(info[1] >= 3) ans = max(ans , info[0]);
            else if(info[2] + 1 == info[0] || info[1] == 2) ans = max(ans , info[0] - 1);
            else ans = max(ans , info[0] - 2);
        }
        
        return ans == 0 ? -1 : ans;
    }
};

