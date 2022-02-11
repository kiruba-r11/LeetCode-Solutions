class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        /*
        
        O(N) time and O(1) space complexity
        Idea -> Sliding Window and Hashing
        
        Check every substring with size equal to s1's size and see if those substrings are any permutation of s1 or not
        
        */
        
        int n1 = s1.size() , n2 = s2.size();
        int i = 0 , j = 0;
        
        vector <int> hash1(26 , 0) , hash2(26 , 0);
        
        // Update the hashmap for the first string
        for(auto i: s1) hash1[i - 'a']++;
        
        while(j < n2) {
            
            int window = j - i + 1;
            
            // If the length of the substring is less than or equal to the window size
            if(window <= n1) {
                
                // Add the jth element to the substring and make corresponding changes in the hashmap too.
                hash2[s2[j] - 'a']++;
                
                // If the substring size is exactly equal to the window, check if the substring has any permutation of string s1 or not.
                if(window == n1) {
                    
                    bool check = true;
                    for(int k = 0; k < 26; k++) {
                        if(hash1[k] != hash2[k]) {
                            check = false;
                            break;
                        }
                    }
                    if(check) return true;
                }
                j++;
                
            } 
            
            // If the length of the substring is greater than the window size
            else {
                
                // Then we have to remove the ith element from the substring, and make corresponding changes in the hashmap too.
                hash2[s2[i] - 'a']--;
                i++;
            }
        }
        
        return false;
    }
};