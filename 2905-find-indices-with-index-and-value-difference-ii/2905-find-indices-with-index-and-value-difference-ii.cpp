class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n = nums.size();
        
        vector <vector <int>> prefix(n , vector <int> (4));
        prefix[0] = {nums[0] , 0 , nums[0] , 0};
        
        for(int i = 0; i < n; i++) {
            
            if(i != 0) {
                if(nums[i] < prefix[i - 1][0]) {
                    prefix[i][0] = nums[i];
                    prefix[i][1] = i;
                } else {
                    prefix[i][0] = prefix[i - 1][0];
                    prefix[i][1] = prefix[i - 1][1];
                }

                if(nums[i] > prefix[i - 1][2]) {
                    prefix[i][2] = nums[i];
                    prefix[i][3] = i;
                } else {
                    prefix[i][2] = prefix[i - 1][2];
                    prefix[i][3] = prefix[i - 1][3];
                }
            }
            
            int idx = i - indexDifference;
            if(idx >= 0) {
                int val1 = abs(prefix[idx][0] - nums[i]);
                int val2 = abs(prefix[idx][2] - nums[i]);
                
                if(val1 >= valueDifference) return {prefix[idx][1] , i};
                if(val2 >= valueDifference) return {prefix[idx][3] , i};
            }
        }
        
        return {-1 , -1};
    }
};