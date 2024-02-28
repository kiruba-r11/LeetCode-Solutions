class Solution {
public:
    int dfs(vector <vector <int>> &matrix , int row , int allow , vector <int> cols) {
    
        if(row == matrix.size()) return 0;
        
        int m = matrix[0].size();
        int newentry = 0;
        
        for(int i = 0; i < m; i++) {
            if(matrix[row][i] == 1) {
                if(cols[i] == 0) newentry++;
            }
        }
        
        // not pick
        int notpick = 0;
        notpick = dfs(matrix , row + 1 , allow , cols);
        
        // pick if possible
        int pick = 0;
        if(newentry <= allow) {
            for(int i = 0; i < m; i++) {
                if(matrix[row][i] == 1) {
                    cols[i] = 1;
                }
            }
            
            pick = 1 + dfs(matrix , row + 1 , allow - newentry , cols);
        }
        
        return max(pick , notpick);
    }
    
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        vector <int> hash(13);
        return dfs(matrix , 0 , numSelect , hash);
    }
};