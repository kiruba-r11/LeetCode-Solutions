class Solution {
public:
    void permutation(vector <int> &nums , vector <int> &cur , vector <vector <int>> &ans) {
        
        if(nums.size() == cur.size()) {
            ans.push_back(cur);
            return;
        }
        
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] != -11) {
                
                // make effort
                int temp = nums[i];
                nums[i] = -11;
                cur.push_back(temp);
                
                permutation(nums , cur , ans);
                
                // undo effort
                cur.pop_back();
                nums[i] = temp;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector <vector <int>> ans;
        vector <int> cur;
        permutation(nums , cur , ans);
        return ans;    
    }
};