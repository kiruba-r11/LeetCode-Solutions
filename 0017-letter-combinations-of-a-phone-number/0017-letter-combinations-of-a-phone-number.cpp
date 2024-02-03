class Solution {
public:
    vector <string> ans;
    
    void letters(string &digits , int i , unordered_map <char , string> &hash , string &cur) {
        
        if(i == digits.size()) {
            if(cur.size()) ans.push_back(cur);
            return;
        }
        
        for(auto ch: hash[digits[i]]) {
            cur.push_back(ch);
            letters(digits , i + 1 , hash , cur);
            cur.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        unordered_map <char , string> hash;
        hash['2'] = "abc";
        hash['3'] = "def";
        hash['4'] = "ghi";
        hash['5'] = "jkl";
        hash['6'] = "mno";
        hash['7'] = "pqrs";
        hash['8'] = "tuv";
        hash['9'] = "wxyz";
        
        string cur = "";
        letters(digits , 0 , hash , cur);
        return ans;
    }
};