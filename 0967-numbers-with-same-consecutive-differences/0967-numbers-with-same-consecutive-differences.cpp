class Solution {
public:
    vector <int> ans;
    void sameDiff(int &cur , int n , int k) {
        
        if(n == 0) {
            ans.push_back(cur);
            return;
        }
        
        int back = cur % 10;
        
        if(k + back < 10) {
            int temp = cur;
            cur = cur * 10 + (k + back);
            sameDiff(cur , n - 1 , k);
            cur = temp;
        }
        if(back - k >= 0) {
            if(k + back != back - k) {
                int temp = cur;
                cur = cur * 10 + (back - k);
                sameDiff(cur , n - 1 , k);
                cur = temp;
            }
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        int cur = 0;
        for(int i = 1; i <= 9; i++) {
            cur = i;
            sameDiff(cur , n - 1 , k);
            cur = 0;
        }
        return ans;
    }
};