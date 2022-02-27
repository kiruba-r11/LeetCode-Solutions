class Solution {
public:
    int minSteps(string s, string t) {
        
        /*
        
        O(N) time and O(1) space complexity
        Idea -> Hashing
            
        The answer to the question is to find the no. of mismatching characters in both the strings.
        
        */
            
        vector <int> hash(26 , 0);
        int n = s.size() , m = t.size();
        
        for(int i = 0; i < n; i++) {
            hash[s[i] - 97]++;
        }
        
        for(int j = 0; j < m; j++) {
            hash[t[j] - 97]--;
        }
        
        int ans = 0;
        
        for(int i = 0; i < 26; i++) {
            ans += abs(hash[i]);
        }
        
        return ans;
    }
};