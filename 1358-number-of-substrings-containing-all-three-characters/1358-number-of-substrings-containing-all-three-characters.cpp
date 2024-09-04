class Solution {
public:
    int numberOfSubstrings(string s) {
        map <char , int> hash;
        int n = s.size(); 
        int i = 0 , j = 0;
        int ans = 0;
        while(j < n) {
            hash[s[j]]++;
            while(hash.size() == 3) {
                hash[s[i]]--;
                if(hash[s[i]] == 0) hash.erase(s[i]);
                i++;
            }
            if(hash.size() != 3) ans += j - i + 1;
            j++;
        }

        int total = n * 1LL * (n + 1) / 2 - ans;
        return total;
    }
};


