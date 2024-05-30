class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector <int> toposort;
        vector <int> indegree(n);
        vector <vector <int>> graph(n);
        
        int m = pre.size();
        for(int i = 0; i < m; i++) {
            graph[pre[i][0]].push_back(pre[i][1]);
            indegree[pre[i][1]]++;
        }
        
        queue <int> q;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        
        while(!q.empty()) {
            int count = q.size();
            for(int i = 0; i < count; i++) {
                int node = q.front();
                q.pop();
                
                toposort.push_back(node);
                
                for(auto adj: graph[node]) {
                    indegree[adj]--;
                    if(indegree[adj] == 0) {
                        q.push(adj);
                    }
                }
            }
        }
        
        if(toposort.size() != n) return {};
        
        reverse(toposort.begin() , toposort.end());
        return toposort;
    }
};