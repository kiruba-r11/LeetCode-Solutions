class Solution {
public:
    vector <int> price;
    int maxval = 0;
    void leafnode(int n , vector <int> &cost , int val) {
        if((2 * n > cost.size()) || (2 * n + 1 > cost.size())) {
            maxval = max(maxval , cost[n - 1] + val);
            price.push_back(cost[n - 1] + val);
            return;
        }
        
        leafnode(2 * n , cost , cost[n - 1] + val);
        leafnode(2 * n + 1 , cost , cost[n - 1] + val);
    }
    
    int ans = 0;
    void findsum(vector <int> &price , int start , int end) {
        
        if(start > end) return;
        if(start == end) {
            ans += price[start];
            return;
        }
        
        int minval = price[start];
        for(int i = start; i <= end; i++) {
            minval = min(minval , price[i]);
        }

        for(int i = start; i <= end; i++) {
            price[i] -= minval;
        }
        
        ans += minval;
        
        int mid = start + (end - start) / 2;
        findsum(price , start , mid);
        findsum(price , mid + 1 , end);
    }
    
    int minIncrements(int n, vector<int>& cost) {
        
        leafnode(1 , cost , 0);
        for(int i = 0; i < price.size(); i++) {
            price[i] = maxval - price[i];
        }
        
        findsum(price , 0 , price.size() - 1);
        return ans;
        
    }
};