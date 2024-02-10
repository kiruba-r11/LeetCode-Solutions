class Solution {
public:
    int ans = 0;
    void dfs(vector <vector <int>> &graph , int src , unordered_map <int , bool> &rest , vector <bool> &visited) {
        
        ans++;
        visited[src] = true;
        for(auto adj: graph[src]) {
            if(!visited[adj] && rest.find(adj) == rest.end()) {
                dfs(graph , adj , rest , visited);
            }
        }
    }
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_map <int , bool> rest;
        for(auto i: restricted) {
            rest[i] = true;
        }
        
        vector <vector <int>> graph(n);
        for(int i = 0; i < n - 1; i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector <bool> visited(n);
        dfs(graph , 0 , rest , visited);
        return ans;
    }
};