class Solution {
public:
    void dfs(vector <vector <int>> &isConnected , int row) {
    
        int n = isConnected.size();
        
        for(int col = 0; col < n; col++) {
            if(isConnected[row][col] == 1) {
                isConnected[row][col] = 0;
                isConnected[col][row] = 0;
                if(row != col) dfs(isConnected , col);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        // Given: Matrix (Imaginary Graph)
        // To find: No. of connected components
        // Approach: Traversal (BFS/DFS)
        
        int n = isConnected.size();
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j] == 1) {
                    ans += 1;
                    dfs(isConnected , i);
                } 
            }    
        }
        
        return ans;
    }
};