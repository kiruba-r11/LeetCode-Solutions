class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector <int> pending(26);
        vector <int> ans;
        
        int n = s.size();
        int lastentry = -1;
        
        for(int i = 0; i < n; i++) pending[s[i] - 'a'] = i;
        
        for(int i = 0 , j = 0; i < n; i++) {
            
            j = max(j , pending[s[i] - 'a']);
            
            if(i == j) {
                ans.push_back(i - lastentry);
                lastentry = i;
            }
        }
        
        return ans;
    }
};