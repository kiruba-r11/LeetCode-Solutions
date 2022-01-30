class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        
        /*
        
        O(N) time and space
        Idea -> Hashing
        
        */
        
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
    }
};