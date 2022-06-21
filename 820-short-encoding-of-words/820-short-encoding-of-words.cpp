class Solution {
public:
    int minimumLengthEncoding(vector<string>& s) {
        map <string , bool> hash;  
        vector <string> words;
        
        for(auto i: s) hash[i] = true;
        for(auto i: hash) words.push_back(i.first);
        
        int ans = 0;
        int n = words.size();
        
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            int m1 = words[i].size();
            int k1 , k2;
            for(int j = 0; j < n; j++) {
                if(i != j) {
                    
                    int m2 = words[j].size();
                    bool check = true;

                    for(k1 = m1 - 1 , k2 = m2 - 1; k1 >= 0 && k2 >= 0; k1-- , k2--) {
                        if(words[i][k1] != words[j][k2]) {
                            check = false;
                            break;
                        }
                    }

                    if(!check || k1 >= 0) {
                        cnt++;
                    }
                }
                
            }
            if(cnt == n - 1) {
                ans += words[i].size() + 1;
            }
        }
        
        return ans;
    }
};