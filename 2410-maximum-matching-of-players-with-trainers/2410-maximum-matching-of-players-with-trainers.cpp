class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
       
        int n = players.size() , m = trainers.size();
        
        sort(players.begin() , players.end());
        sort(trainers.begin() , trainers.end());
        
        int j = 0 , ans = 0;
        for(int i = 0; i < n && j < m; i++) {
            
            while(players[i] > trainers[j]) {
                j++;
                if(j == m) return ans;
            }
            
            if(players[i] <= trainers[j]) {
                j++;
                ans++;
            }
        }
        
        return ans;
    }
};