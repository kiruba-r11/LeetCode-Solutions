class Solution {
public:
    int bs(int key , vector <int> &words) {
    
        int n = words.size();
        int low = 0 , high = n - 1;
        int ans = n;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(words[mid] > key) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return n - ans;
    }
    
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        
        vector <int> hash(26);
        int n = queries.size();
        int m = words.size();
        vector <int> q , w;
        for(int i = 0; i < n; i++) {
            for(auto ch: queries[i]) {
                hash[ch - 'a']++;
            }
            for(int k = 0; k < 26; k++) {
                if(hash[k] != 0) {
                    q.push_back(hash[k]);
                    break;
                }
            }
            hash.clear();
            hash.resize(26);
        }
        
        for(int i = 0; i < m; i++) {
            for(auto ch: words[i]) {
                hash[ch - 'a']++;
            }
            for(int k = 0; k < 26; k++) {
                if(hash[k] != 0) {
                    w.push_back(hash[k]);
                    break;
                }
            }
            hash.clear();
            hash.resize(26);
        }
        
        sort(w.begin() , w.end());
        vector <int> ans(n);
        for(int i = 0; i < n; i++) {
            ans[i] = bs(q[i] , w);
        }
        return ans;
    }
};

