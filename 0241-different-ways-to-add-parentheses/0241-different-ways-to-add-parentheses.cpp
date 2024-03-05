class Solution {
public:
    unordered_map <string , vector <int>> dp;
    vector<int> diffWaysToCompute(string exp) {
        vector <int> ans;
        
        for(int i = 0; i < exp.size(); i++) {
            int ch = exp[i];
            if(ch == '+' || ch == '-' || ch == '*') {
                
                string str_left = exp.substr(0 , i);
                string str_right = exp.substr(i + 1);
                
                vector <int> left;
                vector <int> right;
                
                if(dp.find(str_left) != dp.end()) left = dp[str_left];
                else left = diffWaysToCompute(str_left);
                
                if(dp.find(str_right) != dp.end()) right = dp[str_right];
                else right = diffWaysToCompute(str_right);
                
                for(auto l: left) {
                    for(auto r: right) {
                        if(ch == '+') ans.push_back(l + r);
                        else if(ch == '-') ans.push_back(l - r);
                        else ans.push_back(l * r);
                    }
                }
            }
        }
        if(ans.size() == 0) ans.push_back(stoi(exp));
        return dp[exp] = ans;
    }
};