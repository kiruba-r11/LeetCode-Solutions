class Solution {
public:
    int sssp(vector <vector <pair <int , int>>> &graph , int limit , int src) {
        int n = graph.size();
        int count = 0;
        
        priority_queue <pair <int , int> , vector <pair <int , int>> , 
                        greater <pair <int , int>>> pq;
        pq.push({0 , src});
        
        vector <int> dist(n , INT_MAX);
        dist[src] = 0;
        
        while(!pq.empty()) {
            int node = pq.top().second;
            int weight = pq.top().first;
            pq.pop();
            
            for(auto adj: graph[node]) {
                int new_node = adj.first;
                int new_weight = adj.second;
                
                if(new_weight + weight < dist[new_node]) {
                    dist[new_node] = new_weight + weight;
                    pq.push({new_weight + weight , new_node});
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(i != src && dist[i] <= limit) count++;
        }
        
        return count;
    }
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector <vector <pair <int , int>>> graph(n);
        
        int m = edges.size();
        for(int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            graph[u].push_back({v , w});
            graph[v].push_back({u , w});
        }
        
        vector <int> nodes(n);
        int ans = -1;
        for(int i = 0; i < n; i++) {
            nodes[i] = sssp(graph , distanceThreshold , i);
            if(ans == -1 || nodes[ans] >= nodes[i]) ans = i;
        }
        
        return ans;
    }
};