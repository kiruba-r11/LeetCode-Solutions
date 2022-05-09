class Solution {
public:
    void fillHash(unordered_map <char , string> &hash) {
    
        hash['2'] = "abc";
        hash['3'] = "def";
        hash['4'] = "ghi";
        hash['5'] = "jkl";
        hash['6'] = "mno";
        hash['7'] = "pqrs";
        hash['8'] = "tuv";
        hash['9'] = "wxyz";
        
    }
    
    void solve(string &digits , int index , string &cur , 
               vector <string> &ans , unordered_map <char , string> &hash) {
    
        if(index == digits.size()) {
            ans.push_back(cur);
            return;
        }
        
        string possible = hash[digits[index]];
        for(auto i: possible) {
         
            cur.push_back(i);
            solve(digits , index + 1 , cur , ans , hash);
            cur.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        
        if(digits == "") return {};
        
        unordered_map <char , string> hash;
        fillHash(hash);
        
        vector <string> ans;
        string cur = "";
        
        solve(digits , 0 , cur , ans , hash);
        
        return ans;
    }
};