class Solution {
public:
    string rev(string s) {
    
        int st = 0 , e = s.size() - 1;
        while(st < e) {
            swap(s[st++] , s[e--]);
        }
        
        return s;
    }
    
    string inv(string s) {
        
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') s[i] = '0';
            else s[i] = '1';
        }
        
        return s;
    }
    
    string solve(int n) {
        if(n == 1) return "0";
        string ans = solve(n - 1) + "1" + rev(inv(solve(n - 1)));
        return ans;
    }
    char findKthBit(int n, int k) {
        return solve(n)[k - 1];
    }
};