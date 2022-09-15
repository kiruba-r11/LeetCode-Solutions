class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        map <int , int> hash;
        
        sort(changed.begin() , changed.end());
        for(auto i: changed) hash[i]++;
        
        vector <int> ans;
        
        for(auto i: hash) {
            if(i.second == 0) continue;
            if(i.first == 0) {
                if(i.second & 1) return {};
                else {
                    for(int k = 0; k < i.second / 2; k++) ans.push_back(0);
                    hash[i.first] = 0;
                }
            } else {
                if(hash[i.first * 2] == 0) return {};
                else if(hash[i.first] > hash[i.first * 2]) return {};
                else {
                    for(int k = 0; k < i.second; k++) ans.push_back(i.first);
                    hash[i.first * 2] = abs(hash[i.first * 2] - hash[i.first]);
                    hash[i.first] = 0;
                }
            }  
        }
        
        for(auto i: hash) {
            if(hash[i.second] != 0) return {};
        }
        
        return ans;
    }
};