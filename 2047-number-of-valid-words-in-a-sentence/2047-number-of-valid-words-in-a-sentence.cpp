class Solution {
public:
    int countValidWords(string s) {
        int n = s.size() , count = 0;
        
        for(int i = 0; i < n; i++) {
            
            int j = i;
            int hypen = 0 , punc = 0;
            bool check = true;
            
            while(j < n && s[j] == ' ') {
                j++;
            }
            
            while(j < n && s[j] != ' ') {
                if(isdigit(s[j])) {
                    check = false;
                } else if(s[j] == '-') {
                    hypen++;
                    if(hypen > 1) {
                        check = false;
                    } else {
                        if(j == 0 || j == n - 1 || !islower(s[j - 1]) || !islower(s[j + 1])) {
                            check = false;
                        }
                    }
                } else if(s[j] == '!' || s[j] == '.' || s[j] == ',') {
                    punc++;
                    if(punc > 1) {
                        check = false;
                    } else {
                        if(j + 1 < n && s[j + 1] != ' ') {
                            check = false;
                        }
                    }
                }
                j++;
            }
            
            while(j < n && s[j] == ' ') {
                j++;
            }
            
            i = j - 1;
            
            if(check) count++;
        }
        
        return count;
    }
};