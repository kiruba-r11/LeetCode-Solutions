class Solution {
public:
    set <vector <int>> s;
    vector <vector <int>> ans;
    
    void solve(vector <int> &nums , int idx , vector <int> &cur) {
        
        if(idx == nums.size()) {
            if(s.count(cur) == 0) {
                ans.push_back(cur);
                s.insert(cur);
            }
            return;
        }
        
        solve(nums , idx + 1 , cur);
        
        cur.push_back(nums[idx]);
        solve(nums , idx + 1 , cur);
        cur.pop_back();
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector <int> cur;
        sort(nums.begin() , nums.end());
        solve(nums , 0 , cur);
        return ans;
    }
};
