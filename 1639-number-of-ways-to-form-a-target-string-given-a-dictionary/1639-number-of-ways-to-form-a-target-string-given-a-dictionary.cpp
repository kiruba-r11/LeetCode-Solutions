class Solution {
public:
    int mod = 1e9 + 7;
    
    int solve(vector <string> &words , string &target , vector <vector <int>> &hash) {
        int m = words[0].size() , k = target.size();

        vector <int> next(m + 1 , 1) , cur(m + 1);
        
        for(int i = k - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {

                long long pick = 0 , notPick = 0;
                
                if(hash[j][target[i] - 97] != 0) 
                    pick = (hash[j][target[i] - 97] * 1L * next[j + 1]) % mod;

                notPick = (cur[j + 1]) % mod;

                cur[j] = (pick + notPick) % mod;
            }
            next = cur;
        }
        
        return next[0];
    }
    
    int numWays(vector<string>& words, string target) {
        int n = words.size() , m = words[0].size();
        
        vector <vector <int>> hash(m , vector <int> (26 , 0));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                hash[j][words[i][j] - 97]++;
            }
        }
        
        return solve(words , target , hash);
    }
};