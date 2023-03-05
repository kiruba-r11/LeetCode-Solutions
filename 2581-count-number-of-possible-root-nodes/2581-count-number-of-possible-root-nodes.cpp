class Solution {
public:
    int root_ans(unordered_map <int , vector <int>> &graph , map <pair <int , int> , int> &hash ,
                 unordered_map <int , bool> &visited , int src) {
        
        visited[src] = true;
        int ans = 0;
        for(auto adj: graph[src]) {
            if(visited[adj] == false) {
                ans += hash[{src , adj}] + root_ans(graph , hash , visited , adj);
            } 
        }
        
        return ans;
    }  
    
    int totalans = 0;
    
    void total_ans(unordered_map <int , vector <int>> &graph , map <pair <int , int> , int> &hash ,
                   unordered_map <int , bool> &visited , int src , int curans , int k) {
        
        if(curans >= k) totalans++;
        
        visited[src] = true;
        for(auto adj: graph[src]) {
            if(visited[adj] == false) {
                total_ans(graph , hash , visited , adj , curans - hash[{src , adj}] + hash[{adj , src}] , k);
            }
        }
    }
     
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        
        unordered_map <int , vector <int>> graph;
        int n = edges.size();
        
        for(int i = 0; i < n; i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        map <pair <int , int> , int> hash;
        int m = guesses.size();
        
        for(int i = 0; i < m; i++) {
            hash[{guesses[i][0] , guesses[i][1]}] = 1;
        }
        
        unordered_map <int , bool> visited;
        int curans = root_ans(graph , hash , visited , 0);
        
        visited.clear();
        total_ans(graph , hash , visited , 0 , curans , k);
        
        return totalans;
    }
};