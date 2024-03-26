class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int mask = 0;
        vector <int> prefix(n);
        
        for(int i = 0; i < n; i++) {
            mask = mask ^ (1 << (s[i] - 'a'));
            prefix[i] = mask;
        }

        int m = queries.size();
        vector <bool> ans(m);
        for(int i = 0; i < m; i++) {
            int start = queries[i][0];
            int end = queries[i][1];
            int opr = queries[i][2];
            int curmask = prefix[end] ^ prefix[start] ^ (1 << (s[start] - 'a'));
            int bitcount = __builtin_popcount(curmask);
            if(bitcount <= 2 * opr + 1) ans[i] = true;
        }
        
        return ans;
    }
};