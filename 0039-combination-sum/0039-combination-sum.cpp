class Solution {
public:
    void combination(vector <int> &nums , int i , int &target , vector <int> &cur , 
                     vector <vector <int>> &ans) {
        
        if(target < 0) return;
        if(target == 0) {
            ans.push_back(cur);
            return;
        }
        if(i == nums.size()) return;
        
        // don't choose and move
        combination(nums , i + 1 , target , cur , ans);
        
        // choose and move = choose and don't move (current) + don't choose and move (next)
        
        // choose and don't move 
        cur.push_back(nums[i]);
        target -= nums[i];
        combination(nums , i , target , cur , ans);
        cur.pop_back();
        target += nums[i];
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector <vector <int>> ans;
        vector <int> cur;
        combination(candidates , 0 , target , cur , ans);
        return ans;
    }
};