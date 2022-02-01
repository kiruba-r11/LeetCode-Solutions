class Solution {
public:
    int longestBeautifulSubstring(string word) {
        
        /*
        
        O(N) time and O(1) space complexity
        Idea -> Sliding Window (variable size - max window length is the solution)
        
        */
        
        int i = 0 , j = 0 , n = word.size() , len = 0;
        bool check = true , contin = false;
        
        vector <char> vowels = {'a' , 'e' , 'i' , 'o' , 'u'};
        
        while(j < n) {
            
            contin = false;
            
            for(int k = 0; k < 5; k++) {
                
                check = false;

                // extend for all vowel's in alphabetical order
                while(j < n && word[j] == vowels[k]) {
                    j++;
                    check = true;
                }
                
                // If any vowel is missing, move to next index and start a new substring
                if(!check) {
                    if(k == 0)
                        j++;
                    i = j;
                    contin = true;
                    break;
                }
            }
            
            if(contin) continue;
            
            // It reaches here, only if all vowels with alphabetically ordered substring is found
            len = max(len , j - i);
            i = j;
        }
        
        return len;
    }
};