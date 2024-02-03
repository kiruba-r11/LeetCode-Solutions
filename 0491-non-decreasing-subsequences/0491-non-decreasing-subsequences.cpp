class Solution {
public:
    vector <vector <int>> ans;
    set <vector <int>> s;
    void subsequence(vector <int> &nums , vector <int> &cur , int start) {
        
        if(cur.size() >= 2) {
            if(s.count(cur) == 0) {
                s.insert(cur);
                ans.push_back(cur);
            }
        }
    
        for(int i = start; i < nums.size(); i++) {
            if(nums[i] != -101) {
                if(cur.size() == 0 || cur.back() <= nums[i]) {
                    int temp = nums[i];
                    nums[i] = -101;
                    cur.push_back(temp);
                    
                    subsequence(nums , cur , i + 1);
                    
                    cur.pop_back();
                    nums[i] = temp;
                }
            }
        }
        
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector <int> cur;
        subsequence(nums , cur , 0);
        return ans;
    }
};