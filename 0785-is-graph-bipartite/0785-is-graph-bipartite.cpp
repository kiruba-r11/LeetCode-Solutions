class Solution {
public:
    bool dfs(vector <vector <int>> &graph , int node , vector <int> &color , int clr) {
    
        color[node] = clr;
        
        for(auto adj: graph[node]) {
            if(color[adj] == -1) {
                bool res = dfs(graph , adj , color , 1 - clr);
                if(!res) return false;
            } else if(color[adj] == color[node]) return false;
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector <int> color(n , -1);
        
        for(int i = 0; i < n; i++) {
            if(color[i] == -1) {
                bool res = dfs(graph , i , color , 1);
                if(!res) return false;
            }
        }
        
        return true;
    }
};