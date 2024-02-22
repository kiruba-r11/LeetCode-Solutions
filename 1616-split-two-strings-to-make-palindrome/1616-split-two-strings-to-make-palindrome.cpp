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
        
//         bool check = true;
//         int s = 0 , e = n1 - 1;
//         while(s < e) {
//             if(a[s++] != a[e--]) {
//                 check = false;
//                 break;
//             }
//         }
        
//         if(check) return true;
        
//         s = 0 , e = n2 - 1;
//         while(s < e) {
//             if(b[s++] != b[e--]) {
//                 check = false;
//                 break;
//             }
//         }
        
//         if(check) return true;
        
        while(as < n1 && be >= 0) {
            if(a[as] == b[be]) {
                as++;
                be--;
            } else {
                int splita = as;
                int splitb = be;
                if(ispalindrome(b , as , be)) return true;
                if(ispalindrome(a , as , be)) return true;
                // if(abs(splita - splitb) <= 2) return true;
                // int cnta = as;
                // int cntb = n2 - be - 1;
                // if(cnta != 0 && cnta == cntb) return true;
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
                if(ispalindrome(a , bs , ae)) return true;
                if(ispalindrome(b , bs , ae)) return true;
                // if(abs(splitb - splita) <= 2) return true;
                // int cnta = n1 - ae - 1;
                // int cntb = bs;
                // if(cnta != 0 && cnta == cntb) return true;
                else break;
            }
        }
        
        return as == n1 || bs == n2;
    }
};

/*

"cddb cdbdc"
"cdbc cbddc" 

"ab def"
"fe cab"

"pvhm upgqeltozftlmfjjde"
"yjgp zbezspnnpszebzmhvp"


*/