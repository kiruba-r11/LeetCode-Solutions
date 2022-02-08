class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*
        
        O(N) time and O(1) space complexity
        Idea -> Staircase Search
        
        */
        
        int m = matrix.size() , n = matrix[0].size();
        
        // Start from (0 , n - 1). This element indicates the max in this row, and min in this column
        int row = 0 , col = n - 1;
        
        while(row < m && col >= 0) {
            
            // Return true if target is found
            if(matrix[row][col] == target) return true;
            
            // If target is greater, then since this is the max element in this row, there can't be any other element greater than this in current row. So increment row.
            if(matrix[row][col] < target) row++;
            
            // If target is lesser, then since this is the min element in this column, there can't be any other element lesser than this in current column. So decrement column.
            else col--;
        }
        
        return false;
    }
};