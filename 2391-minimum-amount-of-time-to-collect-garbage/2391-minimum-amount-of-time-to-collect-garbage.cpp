class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        vector <int> cost_g(3);
        vector <int> cost_p(3);
        vector <char> garbage_type = {'M' , 'P' , 'G'};
        
        int n = garbage.size();
        for(int i = 0; i < n; i++) {
            vector <bool> check(3 , false);
            
            for(int k = 0; k < 3; k++) {
                if(i > 0) {
                    cost_p[k] += travel[i - 1];
                }
            }
            
            for(int j = 0; j < garbage[i].size(); j++) {
                for(int k = 0; k < 3; k++) {
                    if(garbage[i][j] == garbage_type[k]) {
                        check[k] = true;
                        cost_g[k]++;
                    }
                }
            }
            
            for(int k = 0; k < 3; k++) {
                if(check[k] == true) {
                    cost_g[k] += cost_p[k];
                    cost_p[k] = 0;
                }
            }
        }
        
        int sum = 0;
        for(int i = 0; i < 3; i++) {
            sum += cost_g[i];
        }
        return sum;
    }
};