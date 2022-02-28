class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        /*
        
        O(N) time and O(N) (output vector) space complexity
        Idea -> Sorted Array Manipulations
        
        */

        int n = nums.size();

        string temp = "";
        vector <string> ans;
        
        for(int i = 0; i < n; i++) {
            int j = i + 1;
            while(j < n && nums[j] - 1 == nums[j - 1]) j++;
            
            int count = j - i;
            if(count == 1) {
                temp = to_string(nums[i]);
                ans.push_back(temp);
            } else {
                temp = to_string(nums[i]) + "->" + to_string(nums[j - 1]);
                ans.push_back(temp);
            }
            i = j - 1;
        }
            
        return ans;
    }
};