class Solution {
public:
    int slide(string &s , int extra) {
    
        int i = 0 , j = 0 , n = s.size() , maxFreq = 0 , ans = 0;
        vector <int> hash(26 , 0);
        
        while(j < n) {
            int window = j - i + 1;
            hash[s[j] - 65]++;
            
            maxFreq = max(maxFreq , hash[s[j] - 65]);
            if(maxFreq + extra < window) {
                hash[s[i] - 65]--;
                i++;
            } else {
                ans = max(ans , window);
            }
            
            j++;
        }
        
        return ans;
    }
    
    int characterReplacement(string s, int k) {
        
        /*
        
        1. Binary Search the window size, and perform Sliding Window with fixed size
            O(26NlogN) time and O(26) space complexity
            O(NlogN) time and O(26) space complexity (with some optimisations)
            
        2. Perform Sliding Window with variable size
            O(26N) time and O(26) space complexity
            O(N) time and O(26) space complexity (with some optimisations)
        
        */
        
        int n = s.size() , ans = 0;
        ans = slide(s , k);
        
        return ans;
    }
};