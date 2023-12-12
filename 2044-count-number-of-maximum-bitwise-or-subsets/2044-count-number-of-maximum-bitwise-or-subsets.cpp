class Solution {
public:
    int maxans = 0;
    int cnt = 0;
    void solve(vector <int> &nums , int i , int &cur) {
        if(i == nums.size()) {
            if(cur > maxans) {
                maxans = max(maxans , cur);
                cnt = 1;
            } else if(cur == maxans) cnt++;
            return;
        }
        
        solve(nums , i + 1 , cur);
        int temp = cur;
        cur = cur | nums[i];
        solve(nums , i + 1 , cur);
        cur = temp;
        
    }
    
    int countMaxOrSubsets(vector<int>& nums) {
        int cur = 0;
        solve(nums , 0 , cur);
        return cnt;
    }
};