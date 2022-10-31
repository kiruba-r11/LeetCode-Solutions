class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        map <int , int> m;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                m[i - j] = -1;
            }
        }
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                if(m[i - j] == -1) {
                    m[i - j] = matrix[i][j];
                }
                else {
                    if(m[i - j] != matrix[i][j])
                        return false;
                }
            }
        }
        return true;
    }
};