class Solution {
public:
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
            cnt[0] = 0;
            for(int i = 1; i < n; i++) {
                if(i & 1) {
                    if(s[i] != '0') cnt[0]++;
                } else {
                    if(s[i] != '1') cnt[0]++;
                }
            }

            // starting with one, and change that
            cnt[1] = 1;
            for(int i = 1; i < n; i++) {
                if(i & 1) {
                    if(s[i] != '1') cnt[1]++;
                } else {
                    if(s[i] != '0') cnt[1]++;
                }
            }
        } else {
            
            // starting with zero, and keep that
            cnt[2] = 0;
            for(int i = 1; i < n; i++) {
                if(i & 1) {
                    if(s[i] != '1') cnt[2]++;
                } else {
                    if(s[i] != '0') cnt[2]++;
                }
            }

            // starting with zero, and change that
            cnt[3] = 1;
            for(int i = 1; i < n; i++) {
                if(i & 1) {
                    if(s[i] != '0') cnt[3]++;
                } else {
                    if(s[i] != '1') cnt[3]++;
                }
            }
        }
        
        
        int ans = 1e7;
        for(auto i: cnt) {
            // cout << i << " ";
            if(!(i & 1))
                ans = min(ans , i / 2);
        }
        
        return ans;
    }
};