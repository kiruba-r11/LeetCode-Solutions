class Solution {
public:
    bool isvowel(char ch) {
        string vowels = "aeiou";
        for(auto i: vowels) {
            if(i == ch) return true;
        }
        return false;
    }
    int beautifulSubstrings(string s, int K) {
        int n = s.size();
        int cnt = 0;
        int k = K;
        int mul = 1;
        
        while(k <= s.size()) {
            while((mul * mul) % K != 0) mul++;
            k = 2 * mul;
            
            if(k <= s.size()) {
                int i = 0 , j = 0;
                int v = 0;

                while(j < n) {
                    int window = j - i + 1;
                    if(window <= k) {
                        if(isvowel(s[j])) v++;
                        if(window == k) {
                            if(v * 2 == k) {
                                cnt++;
                            }
                        }
                        j++;
                    } else {
                        if(isvowel(s[i])) v--;
                        i++;
                    }
                }
            }
            
            mul++;
        }
        
        return cnt;
    }
};


