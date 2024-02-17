class Solution {
public:
    bool condition(string &s , int k) {
    
        int n = s.size();
        int i = 0 , j = 0;
        vector <int> hash(26);
        vector <int> store(26);
        
        while(j < n) {
            int window = j - i + 1;
            if(window <= k) {
                hash[s[j] - 'a']++;
                
                if(window == k) {
                    int cnt = 0;
                    for(int ch = 0; ch < 26; ch++) {
                        if(hash[ch] != 0) {
                            cnt++;
                        }
                    }    
                    if(cnt == 1) {
                        store[s[j] - 'a']++;
                    }
                }
                
                j++;
            } else {
                hash[s[i] - 'a']--;
                i++;
            }
        }
        
        for(int i = 0; i < 26; i++) {
            if(store[i] >= 3) return true;
        }
        
        return false;
    }
    
    int maximumLength(string s) {
        int n = s.size();
        int low = 1 , high = n;
        int ans = -1;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(condition(s , mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};