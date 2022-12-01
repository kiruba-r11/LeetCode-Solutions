class Solution {
public:
    bool halvesAreAlike(string s) {
        int v1 = 0 , v2 = 0;
        int i = 0 , j = s.size() - 1;
        string vowels = "aeiouAEIOU";
        while(i < j) {
            for(int k = 0; k < vowels.size(); k++) {
                if(s[i] == vowels[k]) {
                    v1++;
                    break;
                }
            }
            i++;
            for(int k = 0; k < vowels.size(); k++) {
                if(s[j] == vowels[k]) {
                    v2++;
                    break;
                }
            }
            j--;
        }
        if(v1 == v2)
            return true;
        return false;
    }
};