class Solution {
public:
    bool equals(unordered_map <char , int> &cache , unordered_map <char , int> &hash) {
        if(cache.size() != hash.size()) return false;
        
        for(auto i: cache) {
            if(hash.find(i.first) == hash.end()) return false;
            if(hash[i.first] != cache[i.first]) return false;
        }
        
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int i = 0 , j = 0;
        int n = s.size();
        int m = p.size();
        unordered_map <char , int> hash , cache;
        
        for(int k = 0; k < m; k++) {
            hash[p[k]]++;    
        }
        
        vector <int> ans;
        while(j < n) {
            int window = j - i + 1;
            if(window <= m) {
                cache[s[j]]++;
                if(window == m) {
                    if(equals(cache , hash)) ans.push_back(i);
                }
                j++;
            } else {
                if(cache[s[i]] == 1) cache.erase(s[i]);
                else cache[s[i]]--;
                i++;
            }
        }
        
        return ans;
    }
};