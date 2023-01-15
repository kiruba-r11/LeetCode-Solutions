class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector <vector <int>> ans(n , vector <int> (n));
        
        int m = queries.size();
        for(int i = 0; i < m; i++) {
            int sr = queries[i][0];
            int sc = queries[i][1];
            int er = queries[i][2];
            int ec = queries[i][3];
            
            ans[sr][sc]++;
            
            if(er + 1 < n && ec + 1 < n) ans[er + 1][ec + 1]++;
            if(er + 1 < n) ans[er + 1][sc]--;
            if(ec + 1 < n) ans[sr][ec + 1]--;
        }

        
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < n; j++) {
                ans[i][j] += ans[i][j - 1];
            }
        }
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n; j++) {
                ans[i][j] += ans[i - 1][j];
            }
        }
        
        return ans;
    }
};