class Solution {
public:
    bool ispalindrome(string &s , int start , int end) {
        while(start < end) {
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
    bool checkPalindromeFormation(string a, string b) {
        int n1 = a.size() , n2 = b.size();
        int as = 0 , ae = n1 - 1;
        int bs = 0 , be = n2 - 1;
        
        while(as < n1 && be >= 0) {
            if(a[as] == b[be]) {
                as++;
                be--;
            } else {
                int splita = as;
                int splitb = be;
                if(ispalindrome(b , as , be) || ispalindrome(a , as , be)) return true;
                else break;
            }
        }
        
        while(ae >= 0 && bs < n2) {
            if(a[ae] == b[bs]) {
                ae--;
                bs++;
            } else {
                int splita = ae;
                int splitb = bs;
                if(ispalindrome(a , bs , ae) || ispalindrome(b , bs , ae)) return true;
                else break;
            }
        }
        
        return as == n1 || bs == n2;
    }
};
