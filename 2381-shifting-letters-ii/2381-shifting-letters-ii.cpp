class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        int m = shifts.size();
        
        // Scanline Algorithm
        vector <int> prefix(n + 1);
        for(int i = 0; i < m; i++) {
            int start = shifts[i][0];
            int end = shifts[i][1];
            int val = (shifts[i][2] == 0) ? -1 : 1;
            
            prefix[start] += val;
            prefix[end + 1] -= val;
        }
        
        for(int i = 1; i <= n; i++) prefix[i] += prefix[i - 1];
        
        for(int i = 0; i < n; i++) {
            s[i] = (((s[i] - 'a') + ((prefix[i] + 26) % 26) + 26) % 26 + 'a');
        }
        
        return s;
    }
};