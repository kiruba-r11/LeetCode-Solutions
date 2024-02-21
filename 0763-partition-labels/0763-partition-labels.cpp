class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector <int> pending(26);
        vector <int> entry(26);
        vector <int> ans;
        
        int n = s.size();
        int lastentry = -1;
        
        for(int i = 0; i < n; i++) {
            pending[s[i] - 'a']++;
        }
        
        for(int i = 0; i < n; i++) {
            entry[s[i] - 'a']++;
            pending[s[i] - 'a']--;
            
            bool nope = false;
            
            for(int k = 0; k < 26; k++) {
                if(entry[k] != 0) {
                    if(pending[k] != 0) {
                        nope = true;
                        break;
                    }
                }
            }
            
            if(!nope) {
                entry.clear();
                entry.resize(26);
                ans.push_back(i - lastentry);
                lastentry = i;
            }
        }
        
        return ans;
    }
};