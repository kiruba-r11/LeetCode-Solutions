class Solution {
public:
    void solve(vector <int> &nums , vector <int> &cur , set <vector <int>> &ans , int index) {
        if(index >= nums.size()) {
            if(index == nums.size() && cur.size() > 1) {
                ans.insert(cur);
            }
            return;
        }
        
        if(cur.size() > 1) {
            ans.insert(cur);
        }
        if(cur.size() == 0) {
            cur.push_back(nums[index]);
            solve(nums , cur , ans , index + 1);
            cur.pop_back();
        }
        else if(nums[index] >= cur[cur.size() - 1]) {
            cur.push_back(nums[index]);
            solve(nums , cur , ans , index + 1);
            cur.pop_back();
        }
        solve(nums , cur , ans , index + 1);
        return;
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector <int> cur;
        set <vector <int>> ans;
        vector <vector <int>> res;
        solve(nums , cur , ans , 0);
        for(auto i: ans) {
            res.push_back(i);
        }
        return res;
    }
};