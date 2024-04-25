class Solution {
public:
    bool count(map <int , int> &cnt) {
    
        string s = "aeiou";
        for(auto i: s) {
            if(cnt[i] == 0) return false;
        }
        
        return true;
    }
    
    bool condition(map <int , int> &cnt , char ch) {
    
        string s = "aeiou";
        char last_ch = 'a';
        for(int i = 0; i < 5; i++) {
            if(cnt[s[i]] != 0) last_ch = s[i];
        }
        
        if(last_ch > ch) return false;
        
        return true;
    }
    
    int longestBeautifulSubstring(string word) {
        map <int , int> cnt;
        int n = word.size();
        int i = 0 , j = 0 , ans = 0;
        
        while(j < n) {
            cnt[word[j]]++;
            if(condition(cnt , word[j]) == false) {
                cnt.clear();
                cnt[word[j]]++;
                i = j;
            }
            if(count(cnt)) ans = max(ans , j - i + 1);
            j++;
        }
        
        return ans;
    }
};