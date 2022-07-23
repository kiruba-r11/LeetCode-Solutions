class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        set <int> s;
        int ans = 1;
        for(auto i: rolls) {
            s.insert(i);
            if(s.size() < k) continue;
            ans++;
            s.clear();
        }
        return ans;
    }
};