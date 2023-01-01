class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map <char , string> hash1;
        map <string , char> hash2;
        int i = 0 , j = 0 , n = s.size() , m = pattern.size();
        for(j = 0; j < n; j++) {
            string temp = "";
            while(j < n && s[j] != ' ') {
                temp += s[j];
                j++;
            }
            if(i < m) {
                if(hash1.find(pattern[i]) == hash1.end()) hash1[pattern[i]] = temp;
                else if(hash1[pattern[i]] != temp) return false;

                if(hash2.find(temp) == hash2.end()) hash2[temp] = pattern[i];
                else if(hash2[temp] != pattern[i]) return false;
                
                i++;

            } else return false;
        }

        if(i < m) return false;

        return true;
        
    }
};