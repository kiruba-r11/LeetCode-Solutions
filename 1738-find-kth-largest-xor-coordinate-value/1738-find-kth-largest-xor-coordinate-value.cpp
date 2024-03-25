class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector <vector <int>> prefix(n , vector <int> (m));
        for(int i = 0; i < n; i++) {
            prefix[i][0] = matrix[i][0];
            for(int j = 1; j < m; j++) {
                prefix[i][j] = prefix[i][j - 1] ^ matrix[i][j];
            }
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 1; j < n; j++) {
                prefix[j][i] ^= prefix[j - 1][i];
            }
        }
        
        // Heap trick:
        // 
        priority_queue <int , vector <int> , greater <int>> pq;
        for(auto i: prefix) {
            for(auto j: i) {
                pq.push(j);
                if(pq.size() > k) pq.pop();
            }
        }
        
        return pq.top();
    }
};