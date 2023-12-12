class Solution {
public:
    vector <vector <int>> ans;
    void solve(vector <int> &nums , vector <int> &cur) {
        
        if(cur.size() == nums.size()) {
            ans.push_back(cur);
            return;
        }
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != -11) {
                int temp = nums[i];
                nums[i] = -11;

                cur.push_back(temp);
                solve(nums , cur);
                cur.pop_back();

                nums[i] = temp;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector <int> cur;
        solve(nums , cur);
        return ans;
    }
};