class Solution {
public:
    bool isVowel(char ch) {
        string s = "aeiou";
        for(int i = 0; i < s.size(); i++) {
            if(ch == s[i]) return true;
        }
        return false;
    }
    
    int getIndex(char ch) {
        string s = "aeiou";
        for(int i = 0; i < s.size(); i++) {
            if(ch == s[i]) return i;
        }
        return -1;
    }
    
    int findTheLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;
        vector <int> temp(5 , 0);
        map <vector <int> , int> hash;
        hash[temp] = -1;
        
        for(int i = 0; i < n; i++) {
            if(isVowel(s[i])) {
                temp[getIndex(s[i])]++;
                temp[getIndex(s[i])] %= 2;
            }
            
            if(hash.find(temp) == hash.end()) hash[temp] = i;
            else ans = max(ans , i - hash[temp]);
        }
        
        return ans;
    }
};