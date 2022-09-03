class Solution {
public:
    void solve(int n , int k , int num , vector <int> &ans) {
    
        if(n == 0) {
            if(ans.size()) {
                if(ans.back() != num) ans.push_back(num);
            }
            else ans.push_back(num);
            return;
        }
        
        int last = num % 10;

        if(last + k <= 9) solve(n - 1 , k , num * 10 + (last + k) , ans);
        if(last - k >= 0) solve(n - 1 , k , num * 10 + (last - k) , ans);
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector <int> ans;
        
        for(int start = 1; start <= 9; start++) {
            solve(n - 1 , k , start , ans);
        }
        
        return ans;
    }
};