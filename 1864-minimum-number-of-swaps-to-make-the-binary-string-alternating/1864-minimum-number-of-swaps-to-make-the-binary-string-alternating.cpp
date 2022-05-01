class Solution {
public:
    int helper(string &s , char ch1 , char ch2 , int c) {
        
        int cnt = c , n = s.size();
        for(int i = 1; i < n; i++) {
            if(i & 1) {
                if(s[i] != ch1) cnt++;
            } else {
                if(s[i] != ch2) cnt++;
            }
        }
        
        return cnt;
    }
    int minSwaps(string s) {
        int n = s.size();
        int ones = 0 , zeroes = 0;
        
        for(auto i: s) {
            if(i == '0') zeroes++;
            else ones++;
        }
        
        if(abs(ones - zeroes) > 1) return -1;
        
        vector <int> cnt(4 , 1e7);
        
        if(s[0] == '1') {
            // starting with one, and keep that
            cnt[0] = helper(s , '0' , '1' , 0);

            // starting with one, and change that
            cnt[1] = helper(s , '1' , '0' , 1);
        } else {
            
            // starting with zero, and keep that
            cnt[2] = helper(s , '1' , '0' , 0);

            // starting with zero, and change that
            cnt[3] = helper(s , '0' , '1' , 1);
        }
        
        
        int ans = 1e7;
        for(auto i: cnt) {
            if(!(i & 1)) ans = min(ans , i / 2);
        }
        
        return ans;
    }
};