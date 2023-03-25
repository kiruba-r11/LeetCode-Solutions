class Solution {
public:
    void solve(vector <vector <int>> &graph , int src , vector <bool> &vis , long long &cnt) {
        
        if(vis[src]) return;
        
        cnt++;
        vis[src] = true;
        for(int i = 0; i < graph[src].size(); i++) {
            int newSrc = graph[src][i];
            solve(graph , newSrc , vis , cnt);
        }
        
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector <vector <int>> graph(n);
        int m = edges.size();
        for(int i = 0; i < m; i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector <bool> vis(n);
        vector <long long> cmp;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                long long cnt = 0;
                solve(graph , i , vis , cnt);
                cmp.push_back(cnt);
            }
        }
        
        long long ans = 0;
        sort(cmp.begin() , cmp.end());
        n = cmp.size();
        vector <long long> suffix(n);
        suffix[n - 1] = cmp[n - 1];
        
        for(int i = n - 2; i >= 0; i--) suffix[i] = suffix[i + 1] + cmp[i];
        for(int i = 0; i < n - 1; i++) {
            ans = ans + cmp[i] * (suffix[i + 1]);
        }
        return ans;
    }
};