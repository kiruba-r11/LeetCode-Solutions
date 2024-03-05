class Solution {
public:
    string ans = "";
    int fact(int n) {
        int f = 1;
        for(int i = 1; i <= n; i++) f = f * i;
        return f;
    }
    
    void solve(int n , int k , vector <int> &arr) {
        
        if(n == 0) return;
        
        int idx = k / fact(n - 1) + (k % fact(n - 1) != 0);
        ans.push_back(arr[idx] + '0');
        
        arr.erase(arr.begin() + idx);
        
        k = k % fact(n - 1);
        if(k == 0) k = fact(n - 1);
        
        solve(n - 1 , k , arr);
    }
    string getPermutation(int n, int k) {
        vector <int> arr(n + 1);
        for(int i = 1; i <= n; i++) arr[i] = i;
        solve(n , k , arr);
        return ans;
    }
};