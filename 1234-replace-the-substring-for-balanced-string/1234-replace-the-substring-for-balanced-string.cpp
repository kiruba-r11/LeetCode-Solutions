class Solution {
public:
    int getIndex(char ch) {
        string s = "QWER";
        
        for(int i = 0; i < 4; i++) {
            if(ch == s[i]) return i;
        }
        
        return -1;
    }
    
    bool ispossible(string &s , int k) {
    
        vector <int> hash(4 , 0);
        int n = s.size();
        
        for(int i = 0; i < n; i++) {
            hash[getIndex(s[i])]++;
        }
        
        if(k == 0) {
            int req = n / 4;
            for(int i = 0; i < 4; i++) {
                if(hash[i] != req) return false;
            }
            return true;
        }
        
        int i = 0 , j = 0;
        while(j < n) {
            int window = j - i + 1;
            if(window <= k) {
                hash[getIndex(s[j])]--;
                
                if(window == k) {
                    int space = window;
                    int maxval = 0 , req = 0;

                    for(int idx = 0; idx < 4; idx++) {
                        maxval = max(maxval , hash[idx]);
                    }
                    for(int idx = 0; idx < 4; idx++) {
                        req += maxval - hash[idx];
                    }
                    
                    if(req <= space) {
                        space -= req;
                        if(space % 4 == 0) return true;
                    }
                }
                
                j++;
            } else {
                hash[getIndex(s[i])]++;
                i++;
            }
        }
        return false;
    }
    
    int balancedString(string s) {
        int n = s.size();
        int low = 0 , high = n;
        int ans = high;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            bool check = ispossible(s , mid);
            if(check) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};
