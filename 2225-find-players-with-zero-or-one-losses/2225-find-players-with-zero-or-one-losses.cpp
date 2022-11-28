class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map <int , pair <int , int>> hash;
        
        int n = matches.size();
        for(int i = 0; i < n; i++) {
            int win = matches[i][0];
            int loss = matches[i][1];
            
            if(hash.find(win) == hash.end()) hash[win] = {1 , 0};
            else hash[win] = {hash[win].first + 1 , hash[win].second};
            if(hash.find(loss) == hash.end()) hash[loss] = {0 , 1};
            else hash[loss] = {hash[loss].first , hash[loss].second + 1};
            
        }
        
        vector <vector <int>> ans(2);
        for(auto i: hash) {
            if(i.second.second == 0) ans[0].push_back(i.first);
            if(i.second.second == 1) ans[1].push_back(i.first);
        }
        return ans;
    }
};