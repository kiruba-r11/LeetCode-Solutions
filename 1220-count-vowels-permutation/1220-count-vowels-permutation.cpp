class Solution {
public:
    int mod = 1e9 + 7;
    
    bool isPossible(char prev , char cur) {
     
        if(prev == 'a') {
            if(cur == 'e') return true;
        } else if(prev == 'e') {
            if(cur == 'a' || cur == 'i') return true;
        } else if(prev == 'i') {
            if(cur != 'i') return true;
        } else if(prev == 'o') {
            if(cur == 'i' || cur == 'u') return true;
        } else if(prev == 'u') {
            if(cur == 'a') return true;
        } else {
            return true;
        }
        
        return false;
    }
    
    int helper(char ch) {
        string s = "aeiou-";
        int n = s.size();
        
        for(int i = 0; i < n; i++) {
            if(ch == s[i]) return i;
        }
        
        return -1;
    }
    
    int solve(int n , char lastChar , vector <vector <int>> &dp) {
    
        if(n == 0) return 1;
        
        string s = "aeiou";
        int m = s.size();
        
        int ans = 0;
        
        if(dp[n][helper(lastChar)] != -1) return dp[n][helper(lastChar)];
        
        for(int i = 0; i < m; i++) {
            if(isPossible(lastChar , s[i])) {
                ans += solve(n - 1 , s[i] , dp);
                ans %= mod;
            }
        }
        
        return dp[n][helper(lastChar)] = ans;
    }
    
    int countVowelPermutation(int n) {
        int ans = 0;
        
        vector <vector <int>> dp(n + 1 , vector <int> (6 , -1));
        
        ans = solve(n , '-' , dp);
        return ans;
    }
};