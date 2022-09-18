class Solution {
public:
    int trap(vector<int>& nums) {
        /*
         j
        [0,1,0,2,1,0,1,3,2,1,2,1]
                 j   
        [0,1,1,2,2,2,2,3,3,3,3,3] prefix[j - 1] = 2;
        [3,3,3,3,3,3,3,3,2,2,2,1] suffix[j + 1] = 3; min(3 , 2) => 2
        
        */
        
        int n = nums.size();
        vector <int> prefix(n , 0) , suffix(n , 0);
        
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++) prefix[i] = max(prefix[i - 1] , nums[i]);
        
        suffix[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--) suffix[i] = max(suffix[i + 1] , nums[i]);
        
        int water = 0;
        for(int i = 1; i < n - 1; i++) {
            int height = min(prefix[i - 1] , suffix[i + 1]);
            water += height - nums[i] >= 0 ? height - nums[i] : 0;
        }
        return water;
    }
};