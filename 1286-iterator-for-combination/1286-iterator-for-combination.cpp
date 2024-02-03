class CombinationIterator {
public:
    vector <string> ans;
    int curPtr = 0;
    
    void combination(string &s , int i , int n , string &cur) {
        
        if(n == 0) {
            ans.push_back(cur);
            return;
        }
        
        if(i == s.size()) {
            return;
        }
        
        // make effort
        cur.push_back(s[i]);
        
        // include
        combination(s , i + 1 , n - 1 , cur);
        
        // undo effort
        cur.pop_back();
        
        // exclude
        combination(s , i + 1 , n , cur);
    }
    
    CombinationIterator(string characters, int combinationLength) {
        string cur = "";
        combination(characters , 0 , combinationLength , cur);
    }
    
    string next() {
        return ans[curPtr++];
    }
    
    bool hasNext() {
        return curPtr < ans.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */