class Solution {
public:
    void fill(vector <string> &hash) {
    
        hash = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
    }
    
    int uniqueMorseRepresentations(vector<string>& words) {
        vector <string> hash(26);
        fill(hash);
        
        map <string , int> store;
        for(auto word: words) {
            string code = "";
            for(auto ch: word) {
                code += hash[ch - 'a'];
            }
            store[code] = 1;
        }
        
        return (int)store.size();
    }
};