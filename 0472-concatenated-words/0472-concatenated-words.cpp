class Solution {
private:
    class Node {
    private:
        vector <Node*> arr;
        bool end;
    public:
        Node() {
            arr.resize(27);
            end = false;
        }
        
        bool containsKey(char ch) {
            return arr[ch - 97] != NULL;
        }
        
        void put(char ch , Node* node) {
            arr[ch - 97] = node;
        }
        
        Node* getNext(char ch) {
            return arr[ch - 97];
        }
        
        void setEnd() {
            end = true;
        }
        
        bool isEndSet() {
            return end;
        }
    };
    
    Node* root = new Node();
    
public:
    bool search(string &word , int index , Node* node) {
    
        if(word.size() == index) return node->isEndSet();
        
        if(node->isEndSet()) {
            
            bool newStart = false , oldStart = false;
            newStart = search(word , index  , root);
            
            if(node->containsKey(word[index]))
                oldStart = search(word , index + 1 , node->getNext(word[index]));
            
            return newStart || oldStart;
        }
        
        if(!node->containsKey(word[index])) return false;
        
        return search(word , index + 1 , node->getNext(word[index]));
    }
    
    static bool cmp(string &a , string &b) {
        if(a.size() == b.size())
            return a < b;
        return a.size() < b.size();
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector <string> ans;
        
        sort(words.begin() , words.end() , cmp);
        Node* node;
        
        int n = words.size();
        for(int i = 0; i < n; i++) {
            
            string word = words[i];
            node = root;
            
            bool found = search(word , 0 , node);
            if(found) ans.push_back(word);
            
            node = root;
            
            int m = word.size();
            for(int j = 0; j < m; j++) {
                if(!node->containsKey(word[j])) {
                    node->put(word[j] , new Node());
                }
                node = node->getNext(word[j]);
            }
            
            node->setEnd();
        }
        
        return ans;
    }
};