class Solution {
public:
    int prefixCount(vector<string>& words, string pre) {
        /*
        
        O(N * M) time complexity and O(1) space complexity
        Idea -> Brute force
        
        */
        
        int n = words.size() , m = pre.size() , cnt = 0;
        for(int i = 0; i < n; i++) {
            bool check = true;
            for(int j = 0; j < m; j++) {
                if(words[i][j] != pre[j]) {
                    check = false;
                    break;
                }
            }
            if(check) cnt++;
        }
        return cnt;
    }
};