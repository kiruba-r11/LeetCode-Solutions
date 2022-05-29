class Solution {
public:
    int maxProduct(vector<string>& word) {
        int n = word.size() , ans = 0;
        vector <vector <int>> hash(n , vector <int> (26 , 0));
        
        for(int i = 0; i < n; i++) {
            int m = word[i].size();
            for(int j = 0; j < m; j++) {
                hash[i][word[i][j] - 'a']++;
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; i != j && j < n; j++) {
                bool check = true;
                for(int k = 0; k < 26; k++) {
                    if(hash[i][k] != 0 && hash[j][k] != 0) {
                        check = false;
                        break;
                    }
                }
                if(check) ans = max(ans , (int)word[i].size() * (int)word[j].size());
            }
        }
        
        return ans;
    }
};