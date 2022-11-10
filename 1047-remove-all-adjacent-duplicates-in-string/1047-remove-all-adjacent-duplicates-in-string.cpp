class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        for(auto i: s) {
            if(ans.back() == i) 
                ans.pop_back();
            else
                ans += i;
        }
        return ans;
    }
};