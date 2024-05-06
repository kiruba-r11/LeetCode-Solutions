class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        set <pair <int , int>> s;
        int n = nums.size();
        int i = 0 , j = 0;
        vector <int> ans;
        
        while(j < n) {
            int window = j - i + 1;
            if(window <= k) {
                s.insert({nums[j] , j});
                if(window == k) {
                    ans.push_back(s.rbegin()->first);
                }
                j++;
            } else {
                s.erase({nums[i] , i});
                i++;
            }
        }
        
        return ans;
    }
};