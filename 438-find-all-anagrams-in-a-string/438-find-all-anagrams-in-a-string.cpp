class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        /*
        
        O(N) time and space complexity (O(N*26) time to be precise)
        Idea -> Sliding Window with hashing 
        
        */
        
        vector <int> p_hash(26 , 0) , s_hash(26 , 0);
        vector <int> ans;
        
        // Store p's character counts
        for(auto i: p) {
            p_hash[i - 'a']++;
        }
        
        int p_size = p.size() , s_size = s.size();
        int i = 0 , j = 0;
        
        // Slide in the string s, with window of size p_size
        while(j < s_size) {
            int window_size = j - i + 1;
            
            if(window_size <= p_size) {
                
                s_hash[s[j] - 'a']++;
                
                // If the current window size matches the required window size, check if the string is anagram or not.
                if(window_size == p_size) {
                    
                    bool check = true;
                    
                    // Anagram check
                    for(int k = 0; k < 26; k++) {
                        if(s_hash[k] != p_hash[k]) {
                            check = false;
                            break;
                        }
                    }
                    
                    // If it is anagram, push the starting index of the window
                    if(check) ans.push_back(i);
                } 
                
                j++;
                
            } else {
                
                s_hash[s[i] - 'a']--;
                i++;
            }
        }
        
        return ans;
    }
};