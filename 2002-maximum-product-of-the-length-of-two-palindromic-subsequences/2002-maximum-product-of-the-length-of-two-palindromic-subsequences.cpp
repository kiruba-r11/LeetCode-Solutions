class Solution {
public:
    int ans = 0;
    bool isPalindrome(string &s) {
        int n = s.size();
        int i = 0 , j = n - 1;
        while(i < j) {
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
    
    void solve(string &s , int i , string &cur_a , string &cur_b) {
        
        if(i == s.size()) {
            if(isPalindrome(cur_a) && isPalindrome(cur_b)) {
                ans = max(ans , (int)(cur_a.size() * cur_b.size()));
            }
            return;
        }
        
        solve(s , i + 1 , cur_a , cur_b);
        
        cur_a.push_back(s[i]);
        solve(s , i + 1 , cur_a , cur_b);
        cur_a.pop_back();
        
        cur_b.push_back(s[i]);
        solve(s , i + 1 , cur_a , cur_b);
        cur_b.pop_back();
        
    }
    
    int maxProduct(string s) {
        string cur_a = "" , cur_b = "";
        solve(s , 0 , cur_a , cur_b);
        return ans;
    }
};
