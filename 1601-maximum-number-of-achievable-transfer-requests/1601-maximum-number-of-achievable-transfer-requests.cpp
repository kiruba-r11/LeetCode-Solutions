class Solution {
public:
    int ans = 0;
    void findRequest(vector <int> &building , vector <vector <int>> &requests , int i , int cur) {
        
        if(i == requests.size()) {
            for(auto num: building) {
                if(num != 0) {
                    return;
                }
            }
            
            ans = max(ans , cur);
            return;
        }
        
        
        // make effort
        building[requests[i][0]]--;
        building[requests[i][1]]++;
        
        // include request
        findRequest(building , requests , i + 1 , cur + 1);
        
        // undo effort
        building[requests[i][0]]++;
        building[requests[i][1]]--;
        
        // exclude request
        findRequest(building , requests , i + 1 , cur);
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector <int> building(n);
        findRequest(building , requests , 0 , 0);
        return ans;
    }
};