class Solution {
public:
    vector <vector <int>> ans;
    set <vector <int>> s;
    void solve(vector <int> &nums , vector <int> &cur , int i) {
        
        if(i == nums.size()) {
            if(cur.size() > 1 && s.count(cur) == 0) {
                ans.push_back(cur);
                s.insert(cur);
            }
            return;
        }
        
        solve(nums , cur , i + 1);
        
        if(cur.size() == 0 || cur.back() <= nums[i]) {
            cur.push_back(nums[i]);
            solve(nums , cur , i + 1);
            cur.pop_back();
        }
        
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector <int> cur;
        solve(nums , cur , 0);
        return ans;
    }
};