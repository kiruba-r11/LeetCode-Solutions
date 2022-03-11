class Solution {
public:
    void solve(vector <int> &nums , vector <int> &cur , vector <vector <int>> &ans) {
        
        if(cur.size() == nums.size()) {
            ans.push_back(cur);
            return;
        }
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != -100) {
                cur.push_back(nums[i]);
                int temp = nums[i];
                nums[i] = -100;

                solve(nums , cur , ans);

                nums[i] = temp;
                cur.pop_back();
            }
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector <int> cur;
        vector <vector <int>> ans;
        
        solve(nums , cur , ans);
        return ans;
    }
};