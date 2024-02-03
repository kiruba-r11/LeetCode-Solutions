class Solution {
public:
    
    int ans = INT_MAX;
    void distribute(vector <int> &cookies , int k , vector <int> children , int i) {

        if(i == cookies.size()) {
            int val = children[0];
            for(auto child: children) {
                val = max(val , child);
            }
            
            ans = min(ans , val);
            return;
        }
        
        for(int child = 0; child < k; child++) {
            children[child] += cookies[i];
            distribute(cookies , k , children , i + 1);
            children[child] -= cookies[i];
        }
        
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        if(k == cookies.size()) {
            int ans = INT_MIN;
            for(auto i: cookies) ans = max(ans , i);
            return ans;
        }
        
        vector <int> children(k);
        distribute(cookies , k , children , 0);
        return ans;
    }
};