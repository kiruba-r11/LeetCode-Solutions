class Solution {
public:
    int fpow(int b , int p) {
        if(p == 0) return 1;
        int ans = fpow(b * 1LL * b , p / 2);
        if(p & 1) ans = ans * 1LL * b;
        return ans;
    }
    vector <int> ans;
    void path(int label) {
        if(label == 1) {
            ans.push_back(1);
            return;
        }
        
        ans.push_back(label);
        if(label & 1) {
            label = (label - 1) / 2;
        } else {
            label = label / 2;
        }
        int bits = log(label) / log(2) + 1;
        int start = fpow(2 , bits - 1);
        int end = fpow(2 , bits) - 1;
        
        int rev = end - label + start;
        path(rev);
    }
    vector<int> pathInZigZagTree(int label) {
        path(label);
        reverse(ans.begin() , ans.end());
        return ans;
    }
};
