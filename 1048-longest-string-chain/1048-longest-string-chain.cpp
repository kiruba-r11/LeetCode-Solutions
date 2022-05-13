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
    
//     int solve(vector <string> &words , int index , int select) {
    
//         if(words.size() + 1 == index) return 0;
        
//         if(dp[index][select] != -1) return dp[index][select];
        
//         int pick = 0 , notPick = 0;
//         notPick = solve(words , index + 1 , select);

//         if(select == 0 || isPredecessor(words[select - 1] , words[index - 1]))
//             pick = 1 + solve(words , index + 1 , index);
        
//         return dp[index][select] = max(pick , notPick);
//     }
    
    void move(int *next , int *cur , int n) {
        for(int i = 0; i <= n; i++) {
            next[i] = cur[i];
        }
    }
    
    int solve(vector <string> &words) {
        
        int n = words.size();
        int cur[n + 1] , next[n + 1];
        
        for(int i = 0; i <= n; i++) {
            cur[i] = next[i] = 0;
        }
        
        for(int i = n; i >= 1; i--) {
            for(int j = 0; j <= i; j++) {
                int notPick = next[j];
                int pick = 0;
                
                if(j == 0 || isPredecessor(words[j - 1] , words[i - 1])) pick = 1 + next[i];
                
                cur[j] = max(pick , notPick);
            }
            move(next , cur , n);
        }
        
        return next[0];
    }
    
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin() , words.end() , cmp);
        return solve(words);
    }
};