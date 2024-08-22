class Solution {
public:
    bool is_vowel(char s) {
        string vowel = "aeiou";
        for(auto i: vowel) {
            if(i == s) return true;
        }
        return false;
    }
    
    int get_vowel_id(char s) {
        string vowel = "aeiou";
        for(int i = 0; i < 5; i++) {
            if(vowel[i] == s) return i;
        }
        return -1;
    }
    
    int findTheLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;
        vector <int> prefix(5 , 0);
        map <vector <int> , int> hash;
        hash[{0 , 0 , 0 , 0 , 0}] = -1;
        
        for(int i = 0; i < n; i++) {
            if(is_vowel(s[i])) {
                int pos = get_vowel_id(s[i]);
                prefix[pos]++;
                prefix[pos] %= 2;
            }
            if(hash.find(prefix) != hash.end()) {
                ans = max(ans , i - hash[prefix]);
            } else {
                hash[prefix] = i;
            }
        }
        
        return ans;
    }
};