class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        
        /*
        
        O(1) time and space complexity
        Idea -> The state repeats after every interval of 14
        
        */
        
        n = n % 14;
        if(n == 0) n = 14;
        
        for(int i = 0; i < n; i++) {
            vector <int> temp(8 , 0);
            for(int j = 1; j < 7; j++) {
                if(cells[j - 1] == cells[j + 1]) 
                    temp[j] = 1;
                else 
                    temp[j] = 0;
            }
            cells = temp;
        }
        
        return cells;
    }
};