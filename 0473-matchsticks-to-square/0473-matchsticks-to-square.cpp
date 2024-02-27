class Solution {
public:
    bool dfs(vector <int> &matchsticks , int idx , vector <int> &sq , int sum) {
    
        if(idx == matchsticks.size()) {
            for(int i = 0; i < 4; i++) {
                if(sq[i] != sum) return false;
            }
            return true;
        }
        
        for(int i = 0; i < 4; i++) {
            // pruning condition
            if(sq[i] + matchsticks[idx] <= sum) {
                sq[i] += matchsticks[idx];
                if(dfs(matchsticks , idx + 1 , sq , sum)) return true;
                sq[i] -= matchsticks[idx];
            }
        }
        
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        vector <int> sq(4);
        
        int sum = 0;
        int n = matchsticks.size();
        
        // pruning
        sort(matchsticks.rbegin() , matchsticks.rend());
        for(int i = 0; i < n; i++) sum += matchsticks[i];
        
        if(sum % 4) return false;
        if(matchsticks[0] > sum / 4) return false;
        // ---
        
        return dfs(matchsticks , 0 , sq , sum / 4);
    }
};