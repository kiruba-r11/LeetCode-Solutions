class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int i = 0 , j = 0 , n = word.size() , len = 0;
        bool check = true;
        
        while(j < n) {
            
            // cout << i << " " << j << endl;
            
            check = false;
            
            // extend for all a's
            while(j < n && word[j] == 'a') {
                j++;
                check = true;
            }
            
            if(!check) {
                j++;
                i = j;
                continue;
            }
            
            check = false;
            
            // extend for all e's
            while(j < n && word[j] == 'e') {
                j++;
                check = true;
            }
            
            if(!check) {
                i = j;
                // j++;
                continue;
            }
            
            check = false;
            
            // extend for all i's
            while(j < n && word[j] == 'i') {
                j++;
                check = true;
            }
            
            if(!check) {
                i = j;
                // j++;
                continue;
            }
            
            check = false;
            
            // extend for all o's
            while(j < n && word[j] == 'o') {
                j++;
                check = true;
            }
            
            if(!check) {
                i = j;
                // j++;
                continue;
            }
            
            check = false;
            
            // extend for all u's
            while(j < n && word[j] == 'u') {
                j++;
                check = true;
            }
            
            if(!check) {
                i = j;
                // j++;
                continue;
            }
            
            len = max(len , j - i);
            i = j;
        }
        
        return len;
    }
};