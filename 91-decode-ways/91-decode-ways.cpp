class Solution {
public:
    
    bool isValid(string &t) {
        
        int val = stoi(t);
        return val >= 1 && val <= 26;
    }
    
    int solve(string &s , int index , vector <int> &dp) {
        
        if(index >= s.size()) return 1;
        if(s[index] == '0') return 0;
        
        if(dp[index] != -1) return dp[index];
        
        int one = 0 , two = 0;
        
        one += solve(s , index + 1 , dp);
        
        if(index < s.size() - 1) {
            string t;
            t.push_back(s[index]);
            t.push_back(s[index + 1]);
            
            if(isValid(t)) two += solve(s , index + 2 , dp);
        }
        
        return dp[index] = one + two;
    }
    
    int solve(string &s) {
        
        int n = s.size();
        // vector <int> dp(n + 1 , 0);
        // dp[n] = 1;
        
        int plusTwo = 1 , plusOne = 1 , cur;
        
        for(int i = n - 1; i >= 0; i--) {
            int one = 0 , two = 0;
            
            if(s[i] == '0') cur = 0;
            else {
                if(i + 1 <= n) one = plusOne;
                if(i + 2 <= n) {
                    string t;
                    t.push_back(s[i]);
                    t.push_back(s[i + 1]);
                    if(isValid(t)) two = plusTwo;
                }
                cur = one + two;
            }
            plusTwo = plusOne;
            plusOne = cur;
        }
        
        return plusOne;
    }
    
    int numDecodings(string s) {
        int index = 0 , n = s.size();
        
        // vector <int> dp(n , -1);
        // return solve(s , index , dp);
        return solve(s);
    }
};