class Solution {
public:
    void dfs(vector <vector <int>> &graph , vector <bool> &visited , int src , int dest , 
             vector <int> &cur , vector <vector <int>> &ans) {
        
        if(visited[src] == true) return;
        if(src == dest) {
            cur.push_back(src);
            ans.push_back(cur);
            cur.pop_back();
            return;
        }
        
        visited[src] = true;
        cur.push_back(src);
        
        for(auto i: graph[src]) {
            dfs(graph , visited , i , dest , cur , ans);
        }
        
        visited[src] = false;
        cur.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        int n = graph.size();
        
        vector <vector <int>> ans;
        vector <int> cur;
        vector <bool> visited(n , false);
        
        dfs(graph , visited , 0 , n - 1 , cur , ans);
        
        return ans;
    }
};