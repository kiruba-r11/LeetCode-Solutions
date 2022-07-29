class Solution {
public:
    
    bool isConnected(int x , int y , vector <int> &parent) {
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
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector <vector <int>> graph;
        int n = points.size();
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {                
                
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                
                int wt = abs(x1 - x2) + abs(y1 - y2);
                
                graph.push_back({wt , i , j});
            }
        }
        
        sort(graph.begin() , graph.end());
        
        vector <int> rank(n) , parent(n);
        for(int i = 0; i < n; i++) parent[i] = i;
        
        int sum = 0;
        for(int i = 0; i < graph.size(); i++) {
            int wt = graph[i][0];
            int x = graph[i][1];
            int y = graph[i][2];
            
            if(!isConnected(x , y , parent)) {
                sum += wt;
                unionRank(x , y , parent , rank);
            }
        }
        
        return sum;
    }
};