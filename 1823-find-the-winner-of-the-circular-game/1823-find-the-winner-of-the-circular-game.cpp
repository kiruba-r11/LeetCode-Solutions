class Solution {
public:    
    void solve(int n , int k , int i , vector <int> &v) {
        
        if(n == 1) return;
        
        i = (i + k - 1) % n;
        v.erase(v.begin() + i);
        solve(n - 1 , k , i , v);
    }
    int findTheWinner(int n, int k) {
        vector <int> v(n , 0);
        for(int i = 0; i < n; i++) v[i] = i + 1;
        
        solve(n , k , 0 , v);
        return v[0];
    }
};