class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size() , len = 0 , maxlen = 0;
        queue <int> q;
        long long temp = 0;
        
        
        for(int i = 0; i < n; i++) {
            temp = temp * 2 + (s[i] == '1');
            len++;
            
            if(temp > k) {
                int j = q.front();
                q.pop();
                
                temp -= (1 << (i - j));
                len--;
            }
            
            if(s[i] == '1') q.push(i);
            maxlen = max(maxlen , len);
        }
        
        return maxlen;
    }
};