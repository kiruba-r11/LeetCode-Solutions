class Solution {
public:
    bool solve(string s1 , string s2 , map <string , map <string , bool>> &dp) {
    
        if(s1.size() != s2.size()) return false;
        if(s1 == s2) return true;
        
        if(dp.find(s1) != dp.end()) {
            if(dp[s1].find(s2) != dp[s1].end()) {
                return dp[s1][s2];
            }
        }
        
        int n = s1.size();
        bool flag = false;
        
        for(int i = 1; i < n; i++) {
            
            if((solve(s1.substr(0 , i) , s2.substr(n - i , i) , dp) && 
               solve(s1.substr(i , n - i) , s2.substr(0 , n - i) , dp)) || 
               (solve(s1.substr(0 , i) , s2.substr(0 , i) , dp) && 
                 solve(s1.substr(i , n - i) , s2.substr(i , n - i) , dp))) {
                   flag = true;
                   break;
           }
        }
        
        return dp[s1][s2] = flag;
    }
    
    bool isScramble(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        
        map <string , map <string , bool>> dp;
        return solve(s1 , s2 , dp);
    }
};