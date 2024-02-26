class Solution {
public:
    bool condition(string &s , int k , int allow) {
    
        vector <int> hash(3 , 0);
        int n = s.size();
        for(int i = 0; i < n; i++) hash[s[i] - 'a']++;

        int i = 0 , j = 0;
        while(j < n) {
            int window = j - i + 1;
            if(window <= k) {
                hash[s[j] - 'a']--;
                
                if(window == k) {
                    bool check = true;
                    for(int x = 0; x < 3; x++) {
                        if(hash[x] < allow) {
                            check = false;
                            break;
                        }
                    }
                    if(check) return true;
                }
                
                j++;
            } else {
                
                hash[s[i] - 'a']++;
                i++;
                
            }
        }
        
        return false;
    }
    
    int takeCharacters(string s, int k) {
        int n = s.size();
        int low = 0 , high = n;
        int ans = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(condition(s , mid , k)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans == -1 ? -1 : abs(n - ans);
    }
};