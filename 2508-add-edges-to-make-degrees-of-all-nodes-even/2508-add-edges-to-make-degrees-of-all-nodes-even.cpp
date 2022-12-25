class Solution {
public:
    bool helper(int u , int v , vector <vector <int>> &graph) {
        for(auto adj: graph[u]) if(adj == v) return false;
        return true;
    }
    
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector <vector <int>> graph(n + 1);
        int m = edges.size();
        for(int i = 0; i < m; i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector <int> deg(n + 1);
        for(int i = 1; i <= n; i++) {
            deg[i] = graph[i].size();
        }

        vector <int> nodes;
        for(int i = 1; i <= n; i++) {
            if(deg[i] & 1) nodes.push_back(i);
        }
        
        int cnt = nodes.size();
        if(cnt != 0 && cnt != 2 && cnt != 4) return false;
        
        if(cnt == 0) return true;
        
        if(cnt == 2) {
            if(helper(nodes[0] , nodes[1] , graph)) return true;
            
            for(int i = 1; i <= n; i++) {
                if(i != nodes[0] && i != nodes[1]) {
                    if(helper(nodes[0] , i , graph) && helper(i , nodes[1] , graph)) return true;
                }
            }
            
            return false;
        }

        if(helper(nodes[0] , nodes[1] , graph) && helper(nodes[2] , nodes[3] , graph)) return true;
        if(helper(nodes[0] , nodes[2] , graph) && helper(nodes[1] , nodes[3] , graph)) return true;
        if(helper(nodes[0] , nodes[3] , graph) && helper(nodes[1] , nodes[2] , graph)) return true;

        
        return false;
    }
};