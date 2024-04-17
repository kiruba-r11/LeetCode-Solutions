class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map <int , bool> hash;
        
        for(int i = 0; i < n; i++) {
            hash[nums[i]] = true;
        }
        
        for(int i = 0; i < n; i++) {
            // For a number x, there is no (x-1). 
            // This means, x is the start of the sequence. 
            // Find the max length of the sequence starting with x.
            int current = 0;
            if(hash.find(nums[i] - 1) == hash.end()) {
                int temp = 0;
                while(hash.find(nums[i] + temp) != hash.end()) {
                    current++;
                    temp++;
                }
            }
            ans = max(ans , current);
        }
        
        return ans;
    }
};