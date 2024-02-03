class Solution {
public:
    vector <vector <int>> ans;
    void subsets(vector <int> &nums , int i , bool pick , vector <int> &cur) {
        if(i == nums.size()) {
            ans.push_back(cur);
            return;
        }
        
        subsets(nums , i + 1 , false , cur);
        
        if((i == 0) || (pick) || (!pick && nums[i] != nums[i - 1])) {
            cur.push_back(nums[i]);
            subsets(nums , i + 1 , true , cur);
            cur.pop_back();
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector <int> cur;
        sort(nums.begin() , nums.end());
        subsets(nums , 0 , false , cur);
        return ans;
    }
};

