class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int max_ = max(m , n);
        
        map <int , vector <int>> hash;
        
        for(int i = 0; i < max_; i++) {
            for(int j = 0; j < max_; j++) {
                if(i < m && j < n) {
                    hash[i - j].push_back(mat[i][j]);
                }
            }
        }
        
        for(auto it = hash.begin(); it != hash.end(); it++) {
            sort(it->second.begin() , it->second.end());
        }
        
        for(int i = 0; i < max_; i++) {
            for(int j = 0; j < max_; j++) {
                if(i < m && j < n) {
                    mat[i][j] = hash[i - j][0];
                    hash[i - j].erase(hash[i - j].begin() + 0);
                }
            }
        }
        
        return mat;
    }
};