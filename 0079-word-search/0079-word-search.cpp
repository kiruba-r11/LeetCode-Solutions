class Solution {
public:
    vector <pair <int , int>> dirs = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};
    bool dfs(vector <vector <char>> &grid , string &word , int row , int col , int idx) {
        
        if(idx == word.size()) return true;
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] != word[idx]) return false;
        
        char temp = grid[row][col];
        grid[row][col] = '-';
        
        for(auto dir: dirs) {
            int x = dir.first + row;
            int y = dir.second + col;
            
            if(dfs(grid , word , x , y , idx + 1)) return true;
        }
        
        grid[row][col] = temp;
        
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == word[0]) {
                    bool found = dfs(board , word , i , j , 0);
                    if(found) return true;
                }        
            }
        }
        
        return false;
    }
};