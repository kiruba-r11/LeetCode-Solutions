class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        /*
        
        O(N * M) time and space complexity
        Idea -> Matrix Traversal
        
        */
        
        int n = mat.size() , m = mat[0].size();
        if(n * m != r * c) return mat;
        
        vector <vector <int>> res(r , vector <int> (c , 0));
        int ni = 0 , nj = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                res[ni][nj] = mat[i][j];
                nj++;
                if(nj == c) {
                    ni++;
                    nj = 0;
                }
            }
        }
        
        return res;
    }
};