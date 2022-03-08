class Solution {
public:
    
    bool isSorted(string &word1 , string &word2 , vector <int> &hash) {
        
        int n1 = word1.size() , n2 = word2.size();
        int i = 0 , j = 0;
        
        while(i < n1 && j < n2) {
            if(word1[i] != word2[j]) {
                return hash[word1[i] - 97] < hash[word2[j] - 97];
            }
            i++;
            j++;
        }
            
        
        return n1 <= n2;
    }
    
    bool isAlienSorted(vector<string>& words, string order) {
        
        /*
        
        O(N) time and O(1) space complexity
        Idea -> Just check is adjacent words are sorted
        
        */
        
        int n = order.size();
        vector <int> hash(26 , 0);
        
        for(int i = 0; i < n; i++) {
            hash[order[i] - 97] = i + 1;
        }
        
        int m = words.size();
        
        for(int i = 0; i < m - 1; i++) {
            if(!isSorted(words[i] , words[i + 1] , hash)) return false;
        }
        
        return true;
    }
};