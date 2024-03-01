class Solution {
public:
    int ans = 0;
    void dfs(vector <vector <pair <int , int>>> &graph , int node , vector <int> &visited , vector <int> &values , 
            int maxTime , int score) {
       
        if(maxTime < 0) return;
        
        if(visited[node] == 0) score += values[node];
        
        if(node == 0) ans = max(ans , score);
        
        visited[node]++;
        
        for(auto adj: graph[node]) {
            int dest = adj.first;
            int time = adj.second;
            dfs(graph , dest , visited , values , maxTime - time , score);
        }
        
        visited[node]--;
        
    }
    
    
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        vector <vector <pair <int , int>>> graph(n);
        
        int m = edges.size();
        for(int i = 0; i < m; i++) {
            graph[edges[i][0]].push_back({edges[i][1] , edges[i][2]});
            graph[edges[i][1]].push_back({edges[i][0] , edges[i][2]});
        }

        vector <int> visited(n);
        dfs(graph , 0 , visited , values , maxTime , 0);
        return ans;
        
    }
};