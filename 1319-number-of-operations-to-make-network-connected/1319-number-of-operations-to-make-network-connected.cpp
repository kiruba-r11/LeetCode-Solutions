class Solution {
public:
    void dfs(vector <vector <int>> &graph , vector <bool> &visited , int src) {
        
        visited[src] = true;
        for(auto i: graph[src]) {
            if(!visited[i]) {
                dfs(graph , visited , i);
            }
        }
        
    }
    int makeConnected(int n, vector<vector<int>>& nums) {
        int m = nums.size();
        if(m < n - 1) return -1;
        
        vector <vector <int>> graph(n);
        for(int i = 0; i < m; i++) {
            graph[nums[i][0]].push_back(nums[i][1]);
            graph[nums[i][1]].push_back(nums[i][0]);
        }
        
        int comp = 0;
        vector <bool> visited(n);
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                comp++;
                dfs(graph , visited , i);
            }
        }
        
        return comp - 1;
    }
};