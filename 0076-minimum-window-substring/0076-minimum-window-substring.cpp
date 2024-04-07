class Solution {
public:
    bool valid(vector <int> &shash , vector <int> &thash) {
        for(int i = 0; i < 127; i++) {
            if(shash[i] < thash[i]) return false;
        }
        
        return true;
    }
    
    string minWindow(string s, string t) {
        int n = s.size();
        
        vector <int> shash(127);
        vector <int> thash(127);
        
        for(auto i: t) thash[i]++;
        
        int i = 0 , j = 0;
        int len = n + 1;
        int ansi = -1 , ansj = -1;
        
        while(j < n) {
            shash[s[j]]++;
            while(valid(shash , thash)) {
                if(shash[s[i]] == thash[s[i]]) break;
                shash[s[i]]--;
                i++;
            }

            if(valid(shash , thash) && (j - i + 1 < len)) {
                len = j - i + 1;
                ansi = i , ansj = j;
            }
            j++;
        }
        
        if(ansi == -1 || ansj == -1) return "";
        
        string ans = "";
        for(int i = ansi; i <= ansj; i++) ans.push_back(s[i]);
        
        return ans;
    }
};