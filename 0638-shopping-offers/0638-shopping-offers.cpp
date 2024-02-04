class Solution {
public:
    int ans = INT_MAX;
    void shop(vector <int> &price , vector <int> &needs , vector <vector <int>> &offer , int i , int &cost) {
        
        if(i == offer.size()) {
            
            int tempcost = 0;
            for(int x = 0; x < needs.size(); x++) {
                tempcost += price[x] * needs[x];
            }
            
            ans = min(ans , cost + tempcost);
            return;
        }
        
        shop(price , needs , offer , i + 1 , cost);
        
        bool possible = true;
        for(int x = 0; x < needs.size(); x++) {
            if(offer[i][x] > needs[x]) {
                possible = false;
                break;
            }
        }
        
        if(possible) {
            cost += offer[i][needs.size()];
            for(int x = 0; x < needs.size(); x++) {
                needs[x] -= offer[i][x];
            }
            
            shop(price , needs , offer , i , cost);
            
            cost -= offer[i][needs.size()];
            for(int x = 0; x < needs.size(); x++) {
                needs[x] += offer[i][x];
            }
        }
        
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        
        int cost = 0;
        shop(price , needs , special , 0 , cost);
        
        return ans;
    }
};