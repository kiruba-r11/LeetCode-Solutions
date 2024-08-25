class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map <string , int> hash;
        for(auto word: wordList) {
            hash[word]++;
        }
        
        if(hash.find(endWord) == hash.end()) return 0;
        
        queue <string> q;
        q.push(beginWord);
        map <string , int> visited;
        visited[beginWord]++;
        
        int dist = 0;
        while(!q.empty()) {
            int count = q.size();
            for(int i = 0; i < count; i++) {
                string word = q.front();
                q.pop();
                
                if(word == endWord) return dist + 1;
                
                string new_word = word;
                int len = new_word.size();
                for(int idx = 0; idx < len; idx++) {
                    char c = new_word[idx];
                    for(int ch = 'a'; ch <= 'z'; ch++) {
                        if(ch != new_word[idx]) {
                            new_word[idx] = ch;
                            if(hash.find(new_word) != hash.end() && visited.find(new_word) == visited.end()) {
                                visited[new_word] = true;
                                q.push(new_word);
                            }
                        }
                    }
                    new_word[idx] = c;
                } 
            }
            dist++;
        }
        
        return 0;
    }
};