class Solution {
public:
    bool inbounds(int size , int row , int col) {
        if(row >= 0 && row < size && col >= 0 && col < size) return true;
        return false;
    }
    
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        int m = queries.size();
        vector <vector <int>> ans(n , vector <int> (n));
        
        for(int i = 0; i < m; i++) {
            int si = queries[i][0];
            int sj = queries[i][1];
            int ei = queries[i][2];
            int ej = queries[i][3];
            
            if(inbounds(n , si , sj)) ans[si][sj] += 1;
            if(inbounds(n , ei + 1 , ej + 1)) ans[ei + 1][ej + 1] += 1;
            if(inbounds(n , ei + 1 , sj)) ans[ei + 1][sj] -= 1;
            if(inbounds(n , si , ej + 1)) ans[si][ej + 1] -= 1;
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < n; j++) {
                ans[i][j] += ans[i][j - 1];
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < n; j++) {
                ans[j][i] += ans[j - 1][i];
            }
        }
        
        return ans;
    }
};

// Sweep Line for 2D array
// Given ((si , sj) , (ei , ej)) 
// -> grid[si][sj] += 1
// -> grid[ei + 1][ej + 1] += 1
// -> grid[ei + 1][sj] -= 1
// -> grid[si][ej + 1] -= 1