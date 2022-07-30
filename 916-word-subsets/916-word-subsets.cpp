class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        vector <int> hash(26 , 0);
        
        int n = words1.size() , m = words2.size();
        for(int i = 0; i < m; i++) {
            vector <int> temp(26 , 0);
            for(auto it: words2[i]) {
                temp[it - 'a']++;   
            }
            
            for(int k = 0; k < 26; k++) {
                hash[k] = max(hash[k] , temp[k]);
            }
        }
        
        vector <string> ans;
        
        for(int i = 0; i < n; i++) {
            vector <int> temp(26 , 0);
            for(auto it: words1[i]) {
                temp[it - 'a']++;
            }
            
            bool check = true;
            for(int k = 0; k < 26; k++) {
                if(temp[k] < hash[k]) {
                    check = false;
                    break;
                }
            }
            
            if(check) ans.push_back(words1[i]);
        }
        
        return ans;
    }
};