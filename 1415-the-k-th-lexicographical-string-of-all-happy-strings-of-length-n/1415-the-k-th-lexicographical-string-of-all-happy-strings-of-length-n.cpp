class Solution {
public:
    void solve(string &s , int n , int &k , vector <char> &list , string &ans) {
        
        if(n == 0) {
            k--;
            if(k == 0) {
                ans = s;
            }
            return;
        }
        
        int size = list.size();
        for(int i = 0; i < size; i++) {
            if(s.size() == 0 || (s.size() != 0 && list[i] != s.back())) {
                s.push_back(list[i]);
                solve(s , n - 1 , k , list , ans);
                s.pop_back();
            }  
        }
        
    }
    string getHappyString(int n, int k) {
        
        /*
        
        O(2^N) time and O(N) space (recursive stack) complexity
        Idea -> Backtracking
        
        */
        
        string s = "" , ans = "";
        vector <char> list = {'a' , 'b' , 'c'};
        
        solve(s , n , k , list , ans);
        return ans;
    }
};