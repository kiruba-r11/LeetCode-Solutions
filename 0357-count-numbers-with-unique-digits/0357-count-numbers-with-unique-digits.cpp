class Solution {
public:
    int ans = 1;
    void count(int n , int &cur , vector <int> &used) {
        if(n == 0) return;
        
        for(int i = 0; i <= 9; i++) {
            if(used[i] == 0) {
                if((i == 0 && cur != 0) || (i != 0)) {
                    int temp = cur;
                    used[i]++;
                    cur = cur * 10 + i;
                    ans++;
                    count(n - 1 , cur , used);
                    cur = temp;
                    used[i]--;
                }
            }
        }
    }
    int countNumbersWithUniqueDigits(int n) {
        int cur = 0;
        vector <int> used(10);
        count(n , cur , used);
        return ans;
    }
};