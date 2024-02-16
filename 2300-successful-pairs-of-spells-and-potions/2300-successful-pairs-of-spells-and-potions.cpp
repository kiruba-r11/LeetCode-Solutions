class Solution {
public:
    int bs(vector <int> &potions , long long req) {
    
        int n = potions.size();
        int low = 0 , high = n - 1;
        int ans = n;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(potions[mid] >= req) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
    
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        
        sort(potions.begin() , potions.end());
        vector <int> ans(n);
       
        for(int i = 0; i < n; i++) {
            long long req = success / spells[i] + (success % spells[i] != 0);
            int idx = bs(potions , req);
            ans[i] = m - idx;
        } 
        
        return ans;
    }
};