class Solution {
public:
    
    void dfs(vector <vector <int>> &graph , vector <bool> &visited , int src , int &time , vector <int> &inform , int &ans) {
        visited[src] = true;
        for(int i = 0; i < graph[src].size(); i++) {
            int dest = graph[src][i];
            if(visited[dest] == false) {
                time += inform[src];
                dfs(graph , visited , dest , time , inform , ans);
                ans = max(ans , time);
                time -= inform[src];
            }
        }
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        vector <vector <int>> graph(n);
        for(int i = 0; i < n; i++) {
            if(manager[i] != -1)
                graph[manager[i]].push_back(i);
        }
        
        vector <bool> visited(n , false);
        int time = 0 , ans = 0;
        dfs(graph , visited , headID , time , informTime , ans);
        return ans;
    }
};