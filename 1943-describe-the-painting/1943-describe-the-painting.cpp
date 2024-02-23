class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map <int , long long> prefix;
        int n = segments.size();
        
        for(int i = 0; i < n; i++) {
            int first = segments[i][0];
            int last = segments[i][1];
            int color = segments[i][2];
            
            prefix[first] += color;
            prefix[last] -= color;
        }
        
        int i = 0;
        vector <vector <long long>> ans;
        for(auto it: prefix) {
            if(prefix[i] > 0) {
                ans.push_back({i , it.first , prefix[i]});
            } 
            prefix[it.first] += prefix[i];
            i = it.first;
        } 
        
        return ans;
    }
};

