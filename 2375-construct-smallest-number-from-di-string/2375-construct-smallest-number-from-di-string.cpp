class Solution {
public:
    void smallNumber(string &pattern , string &allowed , string &cur , int idx , string &ans) {
        
        if(idx == pattern.size()) {
            if(ans == "") ans = cur;
            else ans = min(ans , cur);
            return;
        }
    
        for(int i = 0; i < allowed.size(); i++) {
            if(allowed[i] != '-') {
                if((pattern[idx] == 'I' && allowed[i] > cur.back()) || (pattern[idx] == 'D' && allowed[i] < cur.back())) {
                    char temp = allowed[i];
                    allowed[i] = '-';
                    cur.push_back(temp);

                    smallNumber(pattern , allowed , cur , idx + 1 , ans);

                    cur.pop_back();
                    allowed[i] = temp;   
                }
            }
        }
    }
    
    string smallestNumber(string pattern) {
        string allowed = "123456789";
        string ans = "";
        
        for(int i = 0; i < allowed.size(); i++) {
            string cur = "";
            char temp = allowed[i];
            allowed[i] = '-';
            cur.push_back(temp);
            
            smallNumber(pattern , allowed , cur , 0 , ans);
            
            cur.pop_back();
            allowed[i] = temp;
        }
        
        return ans;
    }
};