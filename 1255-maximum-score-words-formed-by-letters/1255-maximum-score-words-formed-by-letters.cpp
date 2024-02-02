class Solution {
public:
    int ans = 0;
    void calScore(vector <string> &words , unordered_map <char , int> &letters , vector <int> &score , int i , int &sumScore) {
        
        if(i == words.size()) {
            ans = max(ans , sumScore);
            return;
        }
    
        // include the current word if possible
        bool possible = true;
        unordered_map <char , int> cnt;
        for(auto ch: words[i]) {
            cnt[ch]++;
        }
        
        for(auto ch: words[i]) {
            if(letters[ch] < cnt[ch]) {
                possible = false;
                break;
            }
        }
        
        if(possible) {
            
            // make effort
            int scores = 0;
            for(auto ch: words[i]) {
                letters[ch]--;
                scores += score[ch - 'a'];
            }
            
            sumScore += scores;
            calScore(words , letters , score , i + 1 , sumScore);
                
            // undo effort
            sumScore -= scores;
            for(auto ch: words[i]) {
                letters[ch]++;
            }
        }
        
        // exclude the current word
        calScore(words , letters , score , i + 1 , sumScore);
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int sumScore = 0;
        unordered_map <char , int> letter_hash;
        
        for(auto ch: letters) {
            letter_hash[ch]++;
        }
        
        calScore(words , letter_hash , score , 0 , sumScore);
        return ans;
    }
};