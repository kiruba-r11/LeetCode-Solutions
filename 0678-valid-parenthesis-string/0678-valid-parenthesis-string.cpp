class Solution {
public:
    bool solve(string &s , int i , int open , int close , vector <vector <vector <int>>> &dp) {
        
        if(close > open) return false;
        
        if(i == s.size()) {
            if(open == close) return true;
            return false;
        }
        
        if(dp[i][open][close] != -1) return dp[i][open][close];
        
        bool open_n = solve(s , i + 1 , open + 1 , close , dp);
        bool close_n = solve(s , i + 1 , open , close + 1 , dp);
        bool empty_n = solve(s , i + 1 , open , close , dp);
        
        if(s[i] == '(') return dp[i][open][close] = open_n;
        else if(s[i] == ')') return dp[i][open][close] = close_n;
        
        return dp[i][open][close] = open_n || close_n || empty_n;
    }
    
    bool checkValidString(string s) {
        int n = s.size();
        vector <vector <vector <int>>> dp(n + 1 , vector <vector <int>> (n + 1 , vector <int> (n + 1 , -1)));
        
        return solve(s , 0 , 0 , 0 , dp);
    }
};