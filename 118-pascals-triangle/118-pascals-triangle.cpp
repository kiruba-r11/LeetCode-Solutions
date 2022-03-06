class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        /*
        
        O(N ^ 2) time and O(N) space complexity
        Idea -> Dynamic Programming
        
        */
        
        int n = numRows;
        
        vector <vector <int>> ans;
        vector <int> prev(n + 1) , cur(n + 1);
        
        prev[0] = 1;
        ans.push_back({1});
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= i; j++) {
                int top = 0 , left = 0;
                top = prev[j];
                if(j - 1 >= 0) left = prev[j - 1];
                
                cur[j] = top + left;
                
            }
            prev = cur;
            vector <int> res;
            for(int j = 0; j <= i; j++) {
                res.push_back(cur[j]);
            }
            ans.push_back(res);
        }
        
        
        return ans;
    }
};