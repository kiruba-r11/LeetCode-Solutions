class Solution {
public:
    int dp[1002][1002];
    
    static bool cmp(string &a , string &b) {
        if(a.size() == b.size()) 
            return a < b;
        return a.size() < b.size();
    }
    
    bool isPredecessor(string &a , string &b) {
    
        int n = b.size() , m = a.size();
        if(n != m + 1) return false;
        
        int i = 0 , j = 0 , check = 0;
        while(i < n && j < m) {
            if(a[j] == b[i]) {
                i++;
                j++;
            } else {
                if(check == 1) return false;
                check = 1;
                i++;
            }
        }
        
        return true;
    }
    
    int solve(vector <string> &words , int index , int select) {
    
        if(words.size() == index) return 0;
        
        if(dp[index][select + 1] != -1) return dp[index][select + 1];
        
        int pick = 0 , notPick = 0;
        notPick = solve(words , index + 1 , select);

        if(select == -1 || isPredecessor(words[select] , words[index]))
            pick = 1 + solve(words , index + 1 , index);
        
        return dp[index][select + 1] = max(pick , notPick);
    }
    
    int longestStrChain(vector<string>& words) {
        
        int n = words.size();
        
        for(int i = 0; i <= 1001; i++) {
            for(int j = 0; j <= 1001; j++) {
                dp[i][j] = -1;
            }
        }
        
        sort(words.begin() , words.end() , cmp);
        return solve(words , 0 , -1);
    }
};