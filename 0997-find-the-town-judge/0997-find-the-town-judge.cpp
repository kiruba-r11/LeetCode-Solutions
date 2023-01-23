class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector <pair <bool , int>> town(n + 1 , {true , 0});
        int m = trust.size();
        
        for(int i = 0; i < m; i++) {
            town[trust[i][0]].first = false;
            town[trust[i][1]].second++;
        }
        
        for(int i = 1; i <= n; i++) {
            if(town[i].first && town[i].second == n - 1) return i;
        }
        
        return -1;
    }
};