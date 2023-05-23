class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long ans = 0;
        
        int negcnt = 0 , zerocnt = 0 , pos = INT_MAX , neg = INT_MIN;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] < 0) {
                    negcnt++;
                    neg = max(neg , matrix[i][j]);
                }
                else if(matrix[i][j] == 0) zerocnt++;
                else pos = min(pos , matrix[i][j]);
                ans += abs(matrix[i][j]);
            }
        }

        if((negcnt & 1) && zerocnt == 0) {
            ans -= 2 * min(abs(neg) , pos);
        }
        
        return ans;
    }
};