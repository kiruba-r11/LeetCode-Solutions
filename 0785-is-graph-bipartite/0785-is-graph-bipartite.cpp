class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector <int> color(n , -1);
        
        queue <int> q;
        
        for(int clr = 0; clr < n; clr++) {
            if(color[clr] == -1) {
                q.push(clr);
                color[clr] = 1;

                while(!q.empty()) {
                    int count = q.size();
                    for(int i = 0; i < count; i++) {
                        int node = q.front();
                        q.pop();

                        for(auto adj: graph[node]) {
                            if(color[adj] == -1) {
                                color[adj] = 1 - color[node];
                                q.push(adj);
                            } else if(color[adj] == color[node]) return false;
                        }
                    }
                }
            }
        }
        
        return true;
    }
};