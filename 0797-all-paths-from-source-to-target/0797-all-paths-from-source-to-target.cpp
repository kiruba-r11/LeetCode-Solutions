class Solution {
public:
    vector <vector <int>> ans;
    
    void solve(vector <vector <int>> &graph , vector <bool> &visited , int src , int dest , vector <int> &cur) {
        
        if(src == dest) {
            cur.push_back(src);
            ans.push_back(cur);
            cur.pop_back();
            
            return;
        }
        
        if(visited[src]) return;
        
        for(auto adj: graph[src]) {
            cur.push_back(src);
            visited[src] = true;
            solve(graph , visited , adj , dest , cur);
            visited[src] = false;
            cur.pop_back();
        }
        
        
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector <bool> visited(n);
        vector <int> cur;
        solve(graph , visited , 0 , n - 1 , cur);
        
        return ans;
    }
};