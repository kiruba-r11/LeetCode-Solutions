class Solution {
public:
    int fpow(long long x, int y , int p) {

        int res = 1;  
 
        x = x % p; 

        if (x == 0) return 0; 

        while (y > 0) {
            if (y & 1)
                res = (res * x) % p;

            y = y >> 1; 
            x = (x * x) % p;
        }
        return res;
    }
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        
        /*
        
        O(N) time and O(1) space
        Idea -> Rolling Hash, Reversed Robin Karp
        
        For some string s = "abcd..."
        Hash[abcd...] = (a * p ^ 0 + b * p ^ 1 + c * p ^ 2 + d * p ^ 3 + ...) % mod
        
        The above Hash can be used to find Hash for any substring
        
        Also, 
        Hash[abcd...] = (a * p ^ (k - 1) + b * p ^ (k - 2) + c * p ^ (k - 3) + d * p (k - 4) + ...) % mod
        
        The above Hash can be used to find the Hash for a substring of window k
        
        But, in the question, the hash is -> (a * p ^ 0 + b * p ^ 1 + ...) % mod
        Its in the reverse direction, so the idea is to reverse the string and apply the Hash Function
        
        Also, for eg, a * p ^ 2 + b * p ^ 1 + c * p ^ 0 => (((a * p) + b) * p + c) % mod = PrevHash
        Now, if we want to add a char to the Hash to find Hash[abcd], its just -> ((PrevHash) * p + d) % mod
        Now, if we want to remove a char from the Hash to find Hash[bcd], its just -> (PrevHash - a * p ^ (k - 1)) % mod
        
        */
       
        long long p = power , hash = 0 , subpow = fpow(p , k - 1 , modulo);
        int i = 0 , j = 0 , n = s.size() , start = -1 , end = -1;
        
        // Reverse the string to apply reverse Robin Karp
        reverse(s.begin() , s.end());
        
        while(j < n) {
            int len = j - i + 1;
            if(len <= k) {
                
                // Hash[abc] = (a * p ^ 2 + b * p ^ 1 + c * p ^ 0) % mod
                // Hash[abc] = (((a * p ^ 0) * p + b) * p + c) % mod
                hash = (hash * p + (s[j] - 'a' + 1)) % modulo;
                if(len == k && hash == hashValue) {
                    start = i;
                    end = j;
                }
                j++;
            } else {
                
                // Hash[abc] = (a * p ^ 2 + b * p ^ 1 + c * p ^ 0) % mod
                // Hash[bc] = (Hash[abc] - a * p ^ 2) % mod
                // For window of length k, Hash[substr] = (Hash[str] - char * p ^ (k - 1)) % mod
                hash = ((hash - (s[i] - 'a' + 1) * (subpow)) % modulo);
                
                // Adjusting on negative values
                hash = hash < 0 ? hash + modulo : hash;
                i++;
            }
        }
        
        string ans = "";
        for(int i = start; i <= end; i++) ans = s[i] + ans;
        
        return ans;
    }
};