class Solution {
public:
    
    void generateAllCombinations(int open , int close , string curCombination , vector <string> &allCombinations) {
        
        // Base Case (Valid)
        if(open == 0 && close == 0) {
            
            allCombinations.push_back(curCombination);
            return;
        }
        
        // Base Case (InValid)
        if(open < 0 || close < 0 || open > close) return;
        
        // Insert open parenthesis
        generateAllCombinations(open - 1 , close , curCombination + "(" , allCombinations);
        
        // Insert close parenthesis
        generateAllCombinations(open , close - 1 , curCombination + ")" , allCombinations);
        
    }
    
    vector<string> generateParenthesis(int n) {
        vector <string> allCombinations;
        string curCombination;
        
        int open = n , close = n;
        
        generateAllCombinations(open , close , curCombination , allCombinations);
        
        return allCombinations;
    }
};