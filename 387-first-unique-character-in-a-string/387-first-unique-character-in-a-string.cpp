class Solution {
public:
    int firstUniqChar(string s) {
        
        /*
        
        O(N) time and O(1) space complexity
        Idea -> Hashing
        
        */
        
        vector <int> hash(26 , 0);
        int n = s.size();
        int ans = -1;
        
        for(int i = 0; i < n; i++) {
            hash[s[i] - 97]++;
        }
        
        for(int i = 0; i < n; i++) {
            if(hash[s[i] - 97] == 1) return i;
        }
        
        return -1;
    }
};