class Solution {
public:
    
    bool isValidRow(vector <vector <char>> &board , int row , int col , char element) {
        
        for(int curCol = 0; curCol < 9; curCol++) {
            if(curCol != col) {
                if(board[row][curCol] == element) return false;
            }
        }
        
        return true;
    }
    
    bool isValidCol(vector <vector <char>> &board , int row , int col , char element) {
        
        for(int curRow = 0; curRow < 9; curRow++) {
            if(curRow != row) {
                if(board[curRow][col] == element) return false;
            }
        }
        
        return true;
    }
    
    bool isValidSquare(vector <vector <char>> &board , int row , int col , char element) {
        
        int startRow = row / 3 * 3;
        int startCol = col / 3 * 3;
        
        for(int curRow = startRow; curRow < startRow + 3; curRow++) {
            for(int curCol = startCol; curCol < startCol + 3; curCol++) {
                if(curRow != row && curCol != col) {
                    if(board[curRow][curCol] == element) return false;
                }
            }
        }
        
        return true;
    }
    
    bool isCurrentValid(vector <vector <char>> &board , int row , int col) {
        
        bool rowCheck = isValidRow(board , row , col , board[row][col]);
        if(!rowCheck) return false;
        
        bool colCheck = isValidCol(board , row , col , board[row][col]);
        if(!colCheck) return false;
        
        bool squareCheck = isValidSquare(board , row , col , board[row][col]);
        if(!squareCheck) return false;
        
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        
        /*
        
        O(N^2) time and O(1) space complexity
        Idea -> Basic Matrix traversal
        
        */
        
        // Check only for filled cells
        for(int row = 0; row < 9; row++) {
            for(int col = 0; col < 9; col++) {
                if(board[row][col] != '.') {
                    bool isValid = isCurrentValid(board , row , col);
                    if(!isValid) return false;
                }
            }
        }
        
        return true;
    }
};