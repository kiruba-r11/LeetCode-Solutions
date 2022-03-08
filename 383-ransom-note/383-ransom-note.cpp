class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        /*
        
        O(N) time and O(1) space complexity
        Idea -> Character Frequency Counting
        
        */
        
        int n = ransomNote.size() , m = magazine.size();
        vector <int> hash(26 , 0);
        
        for(int i = 0; i < m; i++) {
            hash[magazine[i] - 97]++;
        }
        
        for(int i = 0; i < n; i++) {
            hash[ransomNote[i] - 97]--;
        }
        
        for(int i = 0; i < 26; i++) {
            if(hash[i] < 0) return false;
        }
        
        return true;
    }
};