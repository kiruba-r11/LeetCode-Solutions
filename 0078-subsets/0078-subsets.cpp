class Solution {
public:
    int fpow(int base , int power) {
        if(power == 0) return 1;
        if(power & 1) return fpow(base * base , power / 2) * base;
        return fpow(base * base , power / 2);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector <vector <int>> ans;
        
        for(int i = 0; i < fpow(2 , n); i++) {
            vector <int> temp_ans;
            for(int j = 0; j < n; j++) {
                if(i & (1 << j)) {
                    temp_ans.push_back(nums[j]);
                }
            }
            ans.push_back(temp_ans);
        }
        
        return ans;
    }
};