class Solution {
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.size() == 1)
            return "";
        bool check = true;
        for(int i = 0; i < palindrome.size(); i++) {
            if(palindrome[i] != 'a' && i != palindrome.size() / 2) {
                check = false;
                break;
            }
        }
        
        if(check) palindrome[palindrome.size() - 1] = 'b';
        
        for(int i = 0; i < palindrome.size(); i++) {
            if(palindrome[i] != 'a' && !check) {
                palindrome[i] = 'a';
                check = false;
                break;
            }
        }
        return palindrome;
    }
};