class Solution {
public:
    void dfs(vector <vector <int>> &graph , vector <int> &cur , vector <bool> &visited , int src) {
        
        visited[src] = true;
        for(auto i: graph[src]) {
            if(!visited[i]) {
                cur.push_back(i);
                dfs(graph , cur , visited , i);
            }
        }
    }
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector <vector <int>> graph(n);
        
        for(auto i: edges) {
            graph[i[1]].push_back(i[0]);
        }
        
        vector <vector <int>> ans(n);
        for(int i = 0; i < n; i++) {
            vector <int> cur;
            vector <bool> visited(n);
            dfs(graph , cur , visited , i);
            sort(cur.begin() , cur.end());
            ans[i] = cur;
        }
        
        return ans;
    }
};