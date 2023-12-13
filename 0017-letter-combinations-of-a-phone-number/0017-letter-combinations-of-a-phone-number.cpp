class Solution {
public:
    void fill_hash(unordered_map <char , string> &hash) {
    
        hash['2'] = "abc";
        hash['3'] = "def";
        hash['4'] = "ghi";
        hash['5'] = "jkl";
        hash['6'] = "mno";
        hash['7'] = "pqrs";
        hash['8'] = "tuv";
        hash['9'] = "wxyz";
        
    }
    
    void solve(string &digits , int i , unordered_map <char , string> &hash , string &cur , vector <string> &ans) {
        
        if(i == digits.size()) {
            if(cur != "") ans.push_back(cur);
            return;
        }
        
        string possible = hash[digits[i]];
        
        for(auto ch: possible) {
            cur.push_back(ch);
            solve(digits , i + 1 , hash , cur , ans);
            cur.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        unordered_map <char , string> hash;
        fill_hash(hash);
        
        vector <string> ans;
        string cur = "";
        solve(digits , 0 , hash , cur , ans);
        
        return ans;
    }
};