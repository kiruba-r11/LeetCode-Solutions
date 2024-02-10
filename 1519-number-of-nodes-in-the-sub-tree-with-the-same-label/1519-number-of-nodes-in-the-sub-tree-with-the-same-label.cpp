class Solution {
public:
    vector <int> ans;
    vector <int> count(vector <vector <int>> &graph , int src , string &label , vector <bool> &visited) {
        
        visited[src] = true;
        
        if(graph[src].size() == 0) {
            vector <int> t(26 , 0);
            t[label[src] - 'a']++;
            ans[src] = t[label[src] - 'a'];
            return t;
        }
        
        vector <int> hash(26 , 0);
        for(auto adj: graph[src]) {
            if(!visited[adj]) {
                vector <int> t = count(graph , adj , label , visited);

                for(int i = 0; i < 26; i++) {
                    hash[i] += t[i];
                }
            }
        }
        
        hash[label[src] - 'a']++;
        ans[src] = hash[label[src] - 'a'];
        
        return hash;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector <vector <int>> graph(n);
        ans.resize(n);
        for(int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector <bool> visited(n);
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                count(graph , i , labels , visited);
            }
        }
        return ans;
    }
};


