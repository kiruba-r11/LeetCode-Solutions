class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector <int> prefix(102);
        int n = logs.size();
        
        for(int i = 0; i < n; i++) {
            prefix[logs[i][0] - 1950]++;
            prefix[logs[i][1] - 1950]--;
        }
        
        for(int i = 1; i < 102; i++) {
            prefix[i] += prefix[i - 1];
        }
        
        int max_ = 0;
        for(int i = 0; i < 102; i++) {
            if(prefix[i] > prefix[max_]) {
                max_ = i;
            }
        }
        
        return max_ + 1950;
    }
};