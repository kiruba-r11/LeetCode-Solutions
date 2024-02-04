class Solution {
public:
    int ans = INT_MAX;
    int res = INT_MAX;
    
    void dessert(vector <int> &base , vector <int> &topping , int target , int &cost , int idx) {
        
        if(idx == topping.size()) {
            int totalcost = 0;
            int diff = 0;
            for(int i = 0; i < base.size(); i++) {
                totalcost = cost + base[i];
                diff = abs(totalcost - target);
                if(diff < ans) {
                    ans = diff;
                    res = totalcost;
                } else if(diff == ans) {
                    res = min(res , totalcost);
                }
            }
            return;
        }
        
        for(int i = 0; i <= 2; i++) {
            cost += topping[idx] * i;
            dessert(base , topping , target , cost , idx + 1);
            cost -= topping[idx] * i;
        }
        
    }
    
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int cost = 0;
        dessert(baseCosts , toppingCosts , target , cost , 0);
        return res;
    }
};

// n - base -> 1 base 
// m - toppings -> any toppings
// for any toppings -> should be less than or equal to 2