class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int curmask = 0;
        int n = allowed.size();
        
        for(int i = 0; i < n; i++) {
            curmask |= (1 << (allowed[i] - 'a'));
        }

        int ans = 0;
        int m = words.size();
        for(int i = 0; i < m; i++) {
            int mm = words[i].size();
            bool check = true;
            
            for(int j  = 0; j < mm; j++) {
                if(((1 << (words[i][j] - 'a')) & curmask) == 0) {
                    check = false;
                    break;
                }
            }
            
            if(check) ans++;
        }
        
        return ans;
    }
};