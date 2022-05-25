class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        
        unordered_map <int , set <int>> hash;
        for(auto i: logs) {
            hash[i[0]].insert(i[1]);
        }
        
        vector <int> ans(k , 0);
        for(auto i: hash) {
            ans[(i.second).size() - 1]++;
        }
        
        return ans;
    }
};