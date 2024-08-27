class Solution {
public:
    bool solve(string &s , int i , int open , vector <vector <int>> &dp) {
        
        if(open < 0) return false;
        
        if(i == s.size()) {
            if(open == 0) return true;
            return false;
        }
        
        if(dp[i][open] != -1) return dp[i][open];
        
        bool open_n = solve(s , i + 1 , open + 1 , dp);
        bool close_n = solve(s , i + 1 , open - 1 , dp);
        bool empty_n = solve(s , i + 1 , open , dp);
        
        if(s[i] == '(') return dp[i][open] = open_n;
        else if(s[i] == ')') return dp[i][open] = close_n;
        
        return dp[i][open] = open_n || close_n || empty_n;
    }
    
    bool checkValidString(string s) {
        int n = s.size();
        vector <vector <int>> dp(n + 1 , vector <int> (n + 1 , -1));
        
        return solve(s , 0 , 0 , dp);
    }
};