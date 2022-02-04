class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        /*
        
        O(N) time and space complexity
        Idea -> Prefix Sum + Hashing
        
        Generally, if we convert the 0's as -1's, then the subarray with sum 0 will have equal no. of zeroes and ones. So we just need to find the length of longest subarray that gives the sum as 0.
        
        */
     
        unordered_map <int , int> hash;
        
        // Store zero sum in invalid index
        hash[0] = -1;
        
        int n = nums.size() , ans = 0;
        
        for(int i = 0; i < n; i++) {
            
            // If num is zero make it -1
            nums[i] = nums[i] ? 1 : -1;
            
            if(i != 0) 
                // Maintain nums as a prefix sum array
                nums[i] += nums[i - 1];
            
            // If this sum is not found before, then add it to hash 
            if(hash.find(nums[i]) == hash.end()) hash[nums[i]] = i;
            
            // If this sum occurence is found at some index say 'i' and current index is 'j'.
            // Then the sum of elements between (i + 1) to j is zero, which means there are equal no. of ones and zeroes.
            // Also do not update the index, as we need to find the longest result.
            else ans = max(ans , i - hash[nums[i]]);
        }
        
        return ans;
    }
};