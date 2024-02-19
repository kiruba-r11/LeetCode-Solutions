class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        int n = words.size();
        for(int i = 0; i < n; i++) {
            int m = words[i].size();
            int s = 0 , e = m - 1;
            bool check = true;
            while(s < e) {
                if(words[i][s] != words[i][e]) {
                    check = false;
                    break;
                }
                s++;
                e--;
            }
            if(check) return words[i];
        }
        
        return "";
    }
};