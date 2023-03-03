class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size() , m = needle.size();
        for(int i = 0; i < n; i++) {
            bool check = true;
            for(int j = 0 , k = i; j < m; j++ , k++) {
                if(haystack[k] != needle[j]) {
                    check = false;
                    break;
                }
            }
            if(check) return i;
        }
        
        return -1;
    }
};