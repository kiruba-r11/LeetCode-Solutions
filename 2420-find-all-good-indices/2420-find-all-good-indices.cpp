class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        // Prefix Suffix -> Sorted Order Based Pattern
        // Approach 1:
        //      Use True/False to represent the sorted order
        //      Use the latest index which broke sorted order
        //      If the latest index is equal to or farther than required range, then it is sorted in the current range
        
        // Approach 2:
        //      Count the no. of elements in the sorted order
        //      If the no. of elements and the range required is equal, then then range is sorted
        
        
//         int n = nums.size();
//         vector <pair <int , int>> prefix(n);
//         vector <pair <int , int>> suffix(n);
        
        
//         prefix[0] = {1 , -1};
//         for(int i = 1; i < n; i++) {
//             if(nums[i - 1] >= nums[i]) {
//                 prefix[i] = prefix[i - 1];
//             } else {
//                 prefix[i] = {0 , i};
//             }
//         }
        
//         suffix[n - 1] = {1 , n};
//         for(int i = n - 2; i >= 0; i--) {
//             if(nums[i] <= nums[i + 1]) {
//                 suffix[i] = suffix[i + 1];
//             } else {
//                 suffix[i] = {0 , i};
//             }
//         }
        
//         vector <int> ans;
//         for(int i = k; i < n - k; i++) {
//             int leftval = prefix[i - 1].first;
//             int leftidx = prefix[i - 1].second;
//             int rightval = suffix[i + 1].first;
//             int rightidx = suffix[i + 1].second;
            
//             if(leftval == 1 && rightval == 1) {
//                 ans.push_back(i);
//             } else if(leftval == 1) {
//                 if(rightidx >= i + k) ans.push_back(i);
//             } else if(rightval == 1) {
//                 if(leftidx <= i - k) ans.push_back(i);
//             } else {
//                 if(leftidx <= i - k && rightidx >= i + k) ans.push_back(i);
//             }
//         }
        
        int n = nums.size();
        vector <int> prefix(n , 1);
        vector <int> suffix(n , 1);
        
        prefix[0] = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i - 1] >= nums[i]) {
                prefix[i] = prefix[i - 1] + 1;
            } 
        }
        
        suffix[n - 1] = 1;
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] <= nums[i + 1]) {
                suffix[i] = suffix[i + 1] + 1;
            }
        }
        
        vector <int> ans;
        for(int i = k; i < n - k; i++) {
            int pre = prefix[i - 1];
            int suf = suffix[i + 1];
            if(pre >= k && suf >= k) ans.push_back(i);
        }
        
        return ans;
    }
};