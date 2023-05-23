class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        int n = segments.size();
        int m = 0;
        
        for(int i = 0; i < n; i++) {
            m = max(segments[i][1] , m);
        }
        
        vector <pair <long long , int>> prefix(m + 1);
        for(int i = 0; i < n; i++) {
            prefix[segments[i][0]].first += segments[i][2];
            prefix[segments[i][1]].first -= segments[i][2];
            
            // start -> 1
            // end -> 2
            // start + end -> 3
            
            if(prefix[segments[i][0]].second == 2)  
                prefix[segments[i][0]].second = 3;
            else if(prefix[segments[i][0]].second != 3)
                prefix[segments[i][0]].second = 1;
                
            
            if(prefix[segments[i][1]].second == 1)
                prefix[segments[i][1]].second = 3;
            else if(prefix[segments[i][1]].second != 3)
                prefix[segments[i][1]].second = 2;
        }
        
        for(int i = 2; i <= m; i++) {
            prefix[i].first += prefix[i - 1].first;
        }
        
        vector <vector <long long>> ans;
        int start = 1;
        
        for(int i = 2; i <= m; i++) {
            if(prefix[i].second != 0) {
                if(prefix[i - 1].first != 0)
                    ans.push_back({start , i , prefix[i - 1].first});
                start = i;
            }
        }
        
        return ans;
    }
};
