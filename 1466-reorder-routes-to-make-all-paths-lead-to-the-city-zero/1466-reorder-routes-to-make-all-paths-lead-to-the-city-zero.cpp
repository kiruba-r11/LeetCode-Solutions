class Solution {
public:
    void solve(vector <vector <int>> &graph , int src , int &ans , map <vector <int> , bool> &hash , vector <bool> &visited , vector <bool> &reach) {
    
        if(visited[src]) return;
        
        visited[src] = true;
        for(int i = 0; i < graph[src].size(); i++) {
            int newSrc = graph[src][i];

            if(hash.find({src , newSrc}) == hash.end()) {
                if(reach[newSrc]) {
                    reach[src] = true;
                    ans++;
                }
            } else {
                reach[src] = true;
            }
        
            solve(graph , newSrc , ans , hash , visited , reach);
        }
        
    }
    
    int minReorder(int m, vector<vector<int>>& connections) {
        int n = connections.size();
        
        vector <vector <int>> graph(m);
        vector <bool> reach(m , false) , visited(m , false);
        map <vector <int> , bool> hash;
        reach[0] = true;
        
        
        for(int i = 0; i < n; i++) {
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
            hash[{connections[i][0] , connections[i][1]}]= true;
        }
        
        int ans = 0;
        solve(graph , 0 , ans , hash , visited , reach);
        
        return ans;
    }
};