class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        
        /*
        
        O(N) time and space
        Idea -> Hashing
        
        unordered_map <int , int> hash;
        
        // Store the occurence of every number
        for(auto i: nums) hash[i]++;
        
        while(true) {
            
            // If the original is found, double it
            if(hash[original] != 0) original *= 2;
            
            // Else return it
            else break;
        }
        return original;
        
        */
        
        /*
        
        O(NlogN) time and O(1) space
        Idea -> Sorting
        
        */
        
        sort(nums.begin() , nums.end());
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            
            // If original is found, double it. Since the array is sorted, double of original will be found only after this current index if it exisited in the array
            if(nums[i] == original) original *= 2;
        }
        
        return original;
    }
};