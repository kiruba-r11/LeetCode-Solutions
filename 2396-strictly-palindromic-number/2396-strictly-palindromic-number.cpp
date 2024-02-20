class Solution {
public:
    bool ispalindrome(string &s) {
        int i = 0 , j = s.size() - 1;
        while(i < j) {
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
    
    string convert(int n , int i) {
        string s = "";
        while(n) {
            int rem = n % i;
            s += to_string(rem);
            n = n / i;
        }
        return s;
    }
    
    bool isStrictlyPalindromic(int n) {
        for(int i = 2; i <= n - 2; i++) {
            string base = convert(n , i);
            bool ans = ispalindrome(base);
            if(!ans) return ans;
        }
        return true;
    }
};