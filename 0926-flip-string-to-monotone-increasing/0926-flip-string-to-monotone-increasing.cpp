class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        int ones = 0 , zeroes = 0 , pre_ones = 0 , pre_zeroes = 0;
        
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') ones++;
            else zeroes++;
        }
        
        int ans = n;
        for(int i = 0; i <= n; i++) {
            int cur_ans = pre_ones + (zeroes - pre_zeroes);
            ans = min(ans , cur_ans);
            
            if(s[i] == '1') pre_ones++;
            else pre_zeroes++;
        }
        
        return ans;
    }
};