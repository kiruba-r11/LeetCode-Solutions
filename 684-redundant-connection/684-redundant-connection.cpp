class Solution {
public:
    bool isCycle(int x , int y , vector <int> &parent) {
    
        int xp = findParent(x , parent);
        int yp = findParent(y , parent);
        
        return xp == yp;
    }
    
    int findParent(int x , vector <int> &parent) {
        
        if(x == parent[x]) return x;
        
        return parent[x] = findParent(parent[x] , parent);
    }
    
    void unionRank(int x , int y , vector <int> &parent , vector <int> &rank) {
        
        int xp = findParent(x , parent);
        int yp = findParent(y , parent);
        
        if(rank[xp] == rank[yp]) {
            parent[xp] = yp;
            rank[yp]++; 
        } else if(rank[xp] < rank[yp]) {
            parent[xp] = yp;
        } else {
            parent[yp] = xp;
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        vector <int> parent(n + 1) , rank(n + 1);
        
        for(int i = 0; i <= n; i++) parent[i] = i;
        
        vector <int> ans;
        for(int i = 0; i < n; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            if(isCycle(u , v , parent)) {
                ans.clear();
                ans.push_back(u);
                ans.push_back(v);
            }
            else unionRank(u , v , parent , rank);
        }
        
        return ans;
    }
};