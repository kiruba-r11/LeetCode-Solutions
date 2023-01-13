class Solution {
public:
    
    vector <int> solve(vector <vector <int>> &graph , int node , string &labels , vector <int> &ans , vector <bool> &visited) {
        
        visited[node] = true;
        
        if(graph[node].size() == 0) {
            vector <int> hash(26);
            hash[labels[node] - 'a']++;
            ans[node] = hash[labels[node] - 'a'];
            return hash;
        }
        
        vector <int> hash(26);
        hash[labels[node] - 'a']++;
        for(int i = 0; i < graph[node].size(); i++) {
            
            if(visited[graph[node][i]] == false) {
                vector <int> temp = solve(graph , graph[node][i] , labels , ans , visited);

                for(int j = 0; j < 26; j++) {
                    hash[j] += temp[j];
                }
            }
        }
        
        ans[node] = hash[labels[node] - 'a'];
        
        return hash;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        
        vector <vector <int>> graph(n);
        int m = edges.size();
        
        for(int i = 0; i < m; i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector <bool> visited(n);
        vector <int> ans(n);
        
        for(int i = 0; i < n; i++) {
            if(visited[i] == false) {
                solve(graph , i , labels , ans , visited);
            }
        }
        
        return ans;
    }
};