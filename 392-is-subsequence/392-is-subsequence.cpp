class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        /*
        
        O(N) time and O(1) space complexity
        Ideq -> String traversal
        
        */

        int n = s.size() , m = t.size();
        int i , j;
        
        for(i = 0 , j = 0; i < m && j < n; i++) {
            if(s[j] == t[i]) j++;
        }
        
        return j == n;
    }
};