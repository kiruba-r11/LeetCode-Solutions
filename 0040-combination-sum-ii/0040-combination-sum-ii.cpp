class Solution {
public:
    vector <vector <int>> ans;
    void combine(vector <int> &nums , int target , int i , int pick , vector <int> &cur) {
        
        if(target < 0) return;
        
        if(target == 0) {
            ans.push_back(cur);
            return;
        }
        
        if(i == nums.size()) return;
        
        combine(nums , target , i + 1 , false , cur);
        
        if((i == 0) || (pick) || (!pick && nums[i] != nums[i - 1])) {
            cur.push_back(nums[i]);
            combine(nums , target - nums[i] , i + 1 , true , cur);
            cur.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector <int> cur;
        sort(candidates.begin() , candidates.end());
        combine(candidates , target , 0 , false , cur);
        return ans;
    }
};