class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& nums) {
        int m = nums.size();
        
        vector <vector <int>> graph(n);
        vector <int> indegree(n);
        vector <int> topo;
        queue <int> q;
        
        for(int i = 0; i < m; i++) {
            int u = nums[i][0];
            int v = nums[i][1];
            
            indegree[v]++;
            graph[u].push_back(v);
        }
        
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        while(!q.empty()) {
            int count = q.size();
            for(int i = 0; i < count; i++) {
                int node = q.front();
                q.pop();
                
                topo.push_back(node);
                
                for(auto adj: graph[node]) {
                    indegree[adj]--;
                    if(indegree[adj] == 0) {
                        q.push(adj);
                    }
                }
            }
        }
        
        if(topo.size() != n) return {};
        reverse(topo.begin() , topo.end());
        return topo;
    }
};