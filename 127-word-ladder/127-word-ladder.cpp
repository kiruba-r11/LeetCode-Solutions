class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        /*

        O(N * M * logM * 26) time and O(N * M) space complexity
        N -> No. of words in wordlist , M -> No. of chars in each word in wordlist
        
        Idea -> BFS + Hashing

        */
        
        map <string , bool> hash , visited;
        int dist = 1;
        
        for(auto i: wordList) hash[i] = true;
        
        queue <string> q;
        q.push(beginWord);
        
        visited[beginWord] = true;
        
        while(q.size()) {
            int count = q.size();

            // This loop runs for a particular level
            for(int i = 0; i < count; i++) {
                
                string s = q.front();
                q.pop();

                // If endword is found, then return the distance
                if(s == endWord) return dist;
                
                int size = s.size();
                
                // Try finding all possible combinations for each index of the string, and check whether it is present in the wordlist or not
                for(int j = 0; j < size; j++) {

                    char ch = s[j];
                    
                    // For an index in string, try changing to all possible values and check if it is present in the hashmap
                    for(int k = 0; k < 26; k++) {

                        s[j] = char(k + 97);
              
                        // If it is present in hashmap and not visited, add it to the queue and make it visited
                        if(hash[s] == true) {
                            if(visited[s] == false) {

                                visited[s] = true;
                                q.push(s);
                            }
                        }
                    }
                    s[j] = ch;
                }
            }

            dist++;
        }
    
        return 0;
    }
};

