class Solution {
public:
    bool bfs(vector <vector <int>> &graph , vector <bool> &visited , int src , int dest) {
    
        queue <int> q;
        q.push(src);
        
        visited[src] = true;
        
        while(!q.empty()) {
            int count = q.size();
            for(int it = 0; it < count; it++) {
                int node = q.front();
                q.pop();
                
                if(node == dest) return true;
                
                for(auto i: graph[node]) {
                    if(visited[i] == false) {
                        visited[i] = true;
                        q.push(i);
                    }
                }
            }
        }
        
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector <vector <int>> graph(n);
        
        for(auto i: edges) {
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        
        vector <bool> visited(n , false);
        
        return bfs(graph , visited , source , destination);
    }
};