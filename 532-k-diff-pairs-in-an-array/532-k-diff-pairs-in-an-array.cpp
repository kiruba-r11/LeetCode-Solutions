class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        /*
        
        O(NlogN) time and O(N) space complexity
        Idea -> Sorting + Hashing
        
        */
        
        int count = 0 , n = nums.size();
        
        unordered_map <int , int> hash;
        for(int i = 0; i < n; i++) hash[nums[i]]++;
        
        sort(nums.begin() , nums.end());
        
        // Instead of checking if abs(num - k) exists for an arbitary 'num', we can check if (num + k) exists for an arbitart 'num' because abs(num - (num + k)) = k.
        
        for(int i = 0; i < n; i++) {
            if(nums[i] + k == nums[i]) {
                if(hash[nums[i]] >= 2) {
                    count++;
                }
            } else {
                if(hash[nums[i] + k] >= 1) {
                    count++;
                }
            }
            
            // Since, array is sorted, to avoid duplicate pairs, we can make sure the already chosen num is not chosen again
            hash[nums[i] + k] = 0;
        }
        
        return count;
    }
};