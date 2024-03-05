class Solution {
public:
    vector<int> diffWaysToCompute(string exp) {
        vector <int> ans;
        for(int i = 0; i < exp.size(); i++) {
            int ch = exp[i];
            if(ch == '+' || ch == '-' || ch == '*') {
                
                vector <int> left = diffWaysToCompute(exp.substr(0 , i));
                vector <int> right = diffWaysToCompute(exp.substr(i + 1));
                
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
        return ans;
    }
};