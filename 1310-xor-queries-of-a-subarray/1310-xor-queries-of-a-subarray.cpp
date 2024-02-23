class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        int m = queries.size();
        
        vector <int> prefix(n);
        vector <int> ans(m);
        
        prefix[0] = arr[0];
        for(int i = 1; i < n; i++) prefix[i] = prefix[i - 1] ^ arr[i];
      
        for(int i = 0; i < m; i++) {
            ans[i] = prefix[queries[i][1]];
            if(queries[i][0] != 0) ans[i] ^= prefix[queries[i][0] - 1];
        }
        
        return ans;
    }
};