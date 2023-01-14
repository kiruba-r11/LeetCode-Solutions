class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector <vector <char>> hash;
        int n = s1.size();
        
        for(int i = 0; i < n; i++) {
            int m = hash.size();
            int idx1 = -1 , idx2 = -1;
            
            for(int j = 0; j < m; j++) {
                for(auto k: hash[j]) {
                    if(k == s1[i]) {
                        idx1 = j;
                    } 
                    if(k == s2[i]) {
                        idx2 = j;
                    }
                }
            }
            
            if(idx1 == -1 && idx2 == -1) {
                hash.push_back({s1[i] , s2[i]});
            } else if(idx1 == -1) {
                hash[idx2].push_back(s1[i]);
            } else if(idx2 == -1) {
                hash[idx1].push_back(s2[i]);
            } else {
                if(idx1 != idx2) {
                    for(int x = 0; x < hash[idx2].size(); x++) {
                        hash[idx1].push_back(hash[idx2][x]);
                    }
                    hash.erase(hash.begin() + idx2);
                }
            }
            
        }
        
        int m = hash.size();
        for(int i = 0; i < m; i++) {
            sort(hash[i].begin() , hash[i].end());
        }
        
        // for(auto i: hash) {
        //     for(auto j: i) cout << j << " ";
        //     cout << endl;
        // }
        // cout << endl;
        
        string ans = "";
        int n1 = baseStr.size();
        for(int i = 0; i < n1; i++) {
            bool found = false;
            for(int j = 0; j < m; j++) {
                int x = hash[j].size();
                bool check = false;
                for(int k = 0; k < x; k++) {
                    if(hash[j][k] == baseStr[i]) {
                        ans += hash[j][0];
                        check = true;
                        break;
                    }
                }
                if(check) {
                    found = true;
                    break;
                }
            }
            if(!found) ans += baseStr[i];
        }
        
        return ans;
    }
};