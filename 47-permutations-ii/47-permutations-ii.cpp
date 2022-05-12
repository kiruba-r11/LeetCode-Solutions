class Solution {
public:
    void solve(vector <int> &nums , vector <int> &cur , set<vector <int>> &tt , vector <vector <int>> &ans) {
    
        if(cur.size() == nums.size()) {
            if(tt.count(cur) == 0) {
                ans.push_back(cur);
                tt.insert(cur);
            }
            return;
        }
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != -100) {
                int temp = nums[i];
                cur.push_back(nums[i]);
                nums[i] = -100;
                
                solve(nums , cur , tt , ans);
                
                nums[i] = temp;
                cur.pop_back();
            }
        }
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set <vector <int>> s;
        vector <int> cur;
        vector <vector <int>> ans;
        
        solve(nums , cur , s , ans);
        
        return ans;
    }
};