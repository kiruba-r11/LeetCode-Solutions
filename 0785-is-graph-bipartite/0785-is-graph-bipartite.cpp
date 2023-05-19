class Solution {
public:
    bool dfs(vector <vector <int>> &graph , vector <int> &colors , int src , int color) {
    
        colors[src] = color;
        for(int i = 0; i < graph[src].size(); i++) {
            int newSrc = graph[src][i];
            
            if(colors[newSrc] == -1) {
                if(!dfs(graph , colors , newSrc , (color == 1 ? 2 : 1))) return false;
            } else {
                if(color == colors[newSrc]) return false;
            }
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector <int> colors(n , -1);
        
        for(int i = 0; i < n; i++) {
            if(colors[i] == -1) {
                if(!dfs(graph , colors , i , 1)) return false;
            }
        }
        
        return true;
    }
};