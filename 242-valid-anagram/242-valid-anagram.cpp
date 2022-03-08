class Solution {
public:
    bool isAnagram(string s, string t) {
        
        /*
        
        O(N) time and O(1) space complexity
        Idea -> Character Frequency Counter
        
        */
        
        int n = s.size() , m = t.size();
        if(n != m) return false;
        
        vector <int> hash(26 , 0);
        for(int i = 0; i < n; i++) {
            hash[s[i] - 97]++;
            hash[t[i] - 97]--;
        }
        
        for(int i = 0; i < 26; i++) {
            if(hash[i] != 0) return false;
        }
        
        return true;
        
    }
};