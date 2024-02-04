class Solution {
public:
    bool construct(vector <int> &ans , int idx , int n , unordered_map <int , int> &used) {
        if(idx == ans.size()) return true;
        
        if(ans[idx] != 0) return construct(ans , idx + 1 , n , used);
        
        for(int i = n; i >= 1; i--) {
            if(used[i] == false) {
                if(i == 1) {
                    ans[idx] = 1;
                    used[i]++;
                    if(construct(ans , idx + 1 , n , used)) return true;
                    ans[idx] = 0;
                    used[i]--;
                } else {
                    if(idx + i < ans.size()) {
                        if(ans[idx] == 0 && ans[idx + i] == 0) {
                            ans[idx] = i;
                            ans[idx + i] = i;
                            used[i]++;

                            if(construct(ans , idx + 1 , n , used)) return true;

                            ans[idx] = 0;
                            ans[idx + i] = 0;
                            used[i]--;
                        }
                    }
                }
            }
        }
        
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vector <int> ans(2 * n - 1);
        unordered_map <int , int> used;
        construct(ans , 0 , n , used);
        return ans;
    }
};