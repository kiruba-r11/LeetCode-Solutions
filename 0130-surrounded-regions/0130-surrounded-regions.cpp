class Solution {
public:
    vector <pair <int , int>> dirs = {{0 , -1} , {0 , 1} , {-1 , 0} , {1 , 0}};
    void dfs(vector <vector <char>> &board , vector <vector <bool>> &visited , int row , int col , char fill) {
    
        int n = board.size();
        int m = board[0].size();
        
        if(row < 0 || col < 0 || row >= n || col >= m || board[row][col] == 'X' || visited[row][col] == true) return;
        
        visited[row][col] = true;
        board[row][col] = fill;
        for(auto dir: dirs) {
            int x = dir.first + row;
            int y = dir.second + col;
            
            dfs(board , visited , x , y , fill);
        }
    }
    
    void helper_row(vector <vector <char>> &board , vector <vector <bool>> &visited , int row) {
        int n = board.size();
        int m = board[0].size();
        
        for(int j = 0; j < m; j++) {
            if(board[row][j] == 'O') {
                dfs(board , visited , row , j , 'O');
            }
        }
    }
    
    void helper_col(vector <vector <char>> &board , vector <vector <bool>> &visited , int col) {
        int n = board.size();
        int m = board[0].size();
        
        for(int i = 0; i < n; i++) {
            if(board[i][col] == 'O') {
                dfs(board , visited , i , col , 'O');
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        vector <vector <bool>> visited(n , vector <bool> (m));
        
        helper_row(board , visited , 0);
        helper_row(board , visited , n - 1);
        helper_col(board , visited , 0);
        helper_col(board , visited , m - 1);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'O' && visited[i][j] == false) {
                    dfs(board , visited , i , j , 'X');
                }
            }
        }
    }
};