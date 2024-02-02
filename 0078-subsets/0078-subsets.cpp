class Solution {
public:
    void subset(vector <int> &nums , int i , vector <int> &cur , vector <vector <int>> &ans) {
            
        if(i == nums.size()) {
            ans.push_back(cur);
            return;
        }
        
        // exclude element
        subset(nums , i + 1 , cur , ans);
        
        // make effort
        cur.push_back(nums[i]);
        
        // include element
        subset(nums , i + 1 , cur , ans);
        
        // undo effect
        cur.pop_back();
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <vector <int>> ans;
        vector <int> cur;
        subset(nums , 0 , cur , ans);
        return ans;
    }
};