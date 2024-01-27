class Solution {
public:
    bool helper(vector <vector <int>> &nums , int k) {
    
        int n = nums.size();
        bool check = false;
        
        for(int i = 0; i < n; i++) {
            if(k >= nums[i][0] && k <= nums[i][1]) {
                check = true;
                break;
            }
        }
        
        return check;
    }
    
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        for(int i = left; i <= right; i++) {
            if(!helper(ranges , i)) return false;
        }
        
        return true;
    }
};