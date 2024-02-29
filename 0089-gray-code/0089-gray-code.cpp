class Solution {
public:
    vector<int> grayCode(int n) {
        vector <int> ans;
        ans.push_back(0);
        for(int i = 1; i < (1 << n); i++) {
            ans.push_back(i ^ (i >> 1));
        }
        return ans;
    }
};