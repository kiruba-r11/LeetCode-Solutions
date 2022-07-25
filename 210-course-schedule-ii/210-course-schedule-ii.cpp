class Solution {
public:
    
    vector<int> findOrder(int n, vector<vector<int>>& c) {
        
        vector <vector <int>> graph(n);
        vector <int> indegree(n);
        
        for(auto i: c) {
            graph[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        
        vector <int> ans;
        queue <int> q;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
                ans.push_back(i);
                indegree[i] = -1;
            }
        }
        
        while(!q.empty()) {
            int count = q.size(); 
            for(int it = 0; it < count; it++) {
                
                int node = q.front();
                q.pop();
                
                for(auto i: graph[node]) {
                    indegree[i]--;
                    if(indegree[i] == 0) {
                        q.push(i);
                        ans.push_back(i);
                    }
                }
            }
        }
        
        if(ans.size() != n) return {};
        
        return ans;
    }
};