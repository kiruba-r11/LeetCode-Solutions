class Solution {
public:
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
    
    
    int longestStrChain(vector<string>& words) {
       
        int n = words.size();
        vector <int> dp(n , 1);
    
        sort(words.begin() , words.end() , cmp);
        
        int len = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(isPredecessor(words[j] , words[i])) {
                    dp[i] = max(dp[i] , 1 + dp[j]);
                }
            }
            
            len = max(len , dp[i]);
        }
        
        return len;
    }
};
