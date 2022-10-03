class Solution {
public:
    int minCost(string cost, vector<int>& s) {
        int ans = 0;
        
        for(int i = 0; i < cost.size();) {
            int j = i;
            int sum = 0;
            int max_elem = INT_MIN;
            while(j < cost.size() && cost[j] == cost[i]) {
                sum += s[j];
                max_elem = max(max_elem , s[j]);
                j++;
            }
            sum -= max_elem;
            ans += sum;
            i = j;
        }
        
        return ans;
    }
};