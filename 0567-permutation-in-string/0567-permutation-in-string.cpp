class Solution {
public:
    bool checkInclusion(string s1, string s) {
        vector <int> hash(26);
        int n1 = s1.size();
        for(int i = 0; i < n1; i++) {
            hash[s1[i] - 'a']++;
        }
        
        int n = s.size();
        int i = 0 , j = 0;
        while(j < n) {
            int window = j - i + 1;
            if(window <= n1) {
                hash[s[j] - 'a']--;
                
                if(window == n1) {
                    bool check = true;
                    for(int k = 0; k < 26; k++) {
                        if(hash[k] != 0) {
                            check = false;
                            break;
                        }
                    }
                    if(check) return true;
                }
                
                j++;
            } else {
                hash[s[i] - 'a']++;
                i++;
            }
        }
        
        return false;
    }
};