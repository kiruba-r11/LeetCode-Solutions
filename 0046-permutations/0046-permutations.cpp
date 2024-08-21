class Solution {
public:
    void solve(vector <int> &nums , int idx , vector <int> &cur , vector <vector <int>> &ans) {
        int n = nums.size();
        
        if(idx == n) {
            ans.push_back(cur);
            return;
        }
            
        for(int i = 0; i < n; i++) {
            if(nums[i] != -11) {
                int temp = nums[i];
                nums[i] = -11;
                
                cur.push_back(temp);
                solve(nums , idx + 1 , cur , ans);
                cur.pop_back();
                
                nums[i] = temp;
            }
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector <int> cur;
        vector <vector <int>> ans;
        solve(nums , 0 , cur , ans);
        return ans;
    }
};