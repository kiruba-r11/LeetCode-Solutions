class Solution {
public:
    vector <int> ans;
    void solve(int n , int k , int &cur , int last) {
        
        if(n == 0) {
            ans.push_back(cur);
            return;
        }
        
        int add = last + k;
        int sub = last - k;
        int temp = cur;
        
        if(add == sub) {
            cur = cur * 10 + add;
            solve(n - 1 , k , cur , add);
            cur = temp;
        } else {
            if(add <= 9) {
                cur = cur * 10 + add;
                solve(n - 1 , k , cur , add);
                cur = temp;
            }

            if(sub >= 0) {
                cur = cur * 10 + sub;
                solve(n - 1 , k , cur , sub);
                cur = temp;
            }
        }
        
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i = 1; i <= 9; i++) {
            solve(n - 1 , k , i , i);
        }
        
        return ans;
    }
};