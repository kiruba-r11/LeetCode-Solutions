class Solution {
public:
    void happyString(int n , string &cur , int &k , string &ans) {
        
        if(n == 0) {
            k--;
            if(k == 0) ans = cur;
            return;
        }
    
        for(int i = 'a'; i <= 'c'; i++) {
            if(cur.size() == 0 || cur.back() != i) {
                cur.push_back(i);
                happyString(n - 1 , cur , k , ans);
                cur.pop_back();
            }
        }
        
    }
    
    string getHappyString(int n, int k) {
        string ans = "";
        string cur = "";
        
        happyString(n , cur , k , ans);
        
        return ans;
    }
};