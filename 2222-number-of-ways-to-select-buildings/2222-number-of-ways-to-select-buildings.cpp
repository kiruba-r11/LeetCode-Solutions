class Solution {
public:
    long long numberOfWays(string s) {
        long long ans = 0;
        int n = s.size();
        
        int tz = 0 , to = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '0') tz++;
            else to++;
        }
        
        int pz = 0 , po = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                if(pz != 0 && (tz - pz) != 0) {
                    ans += pz * 1LL * (tz - pz);
                }
                po++;
            } else {
                if(po != 0 && (to - po) != 0) {
                    ans += po * 1LL * (to - po);
                }
                pz++;
            }
        }
        
        return ans;
    }
};