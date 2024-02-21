class Solution {
public:
    bool condition(string &query , string &pattern) {
    
        int n = query.size();
        int m = pattern.size();
        
        int i = 0 , j = 0;
        while(i < n && j < m) {
            if(query[i] == pattern[j]) {
                i++;
                j++;
            } else {
                if(query[i] >= 65 && query[i] <= 90) return false;
                i++;
            }
        }
        
        while(i < n) {
            if(query[i] >= 65 && query[i] <= 90) return false;
            i++;
        }
        
        return i == n && j == m;
    }
    
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int n = queries.size();
        vector <bool> ans(n);
        
        
        for(int i = 0; i < n; i++) {
            ans[i] = condition(queries[i] , pattern);
        }
        
        return ans;
    }
};