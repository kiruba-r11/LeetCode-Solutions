class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        
        /*
        
        O(NlogN) time and O(1) space complexity
        Idea -> 
        
            1. For the sequence to be in AP, the should have a common difference d. 
            2. The only way the sequence can exist with a common difference d is either in increasing or decreasing order.
            3. So sort them and find whether there exists a common difference d.
        
        */
        
        sort(arr.begin() , arr.end());
        
        int n = arr.size();
        int d = arr[1] - arr[0];
        
        for(int i = 2; i < n; i++) {
            if(arr[i] - arr[i - 1] != d) return false;
        }
        
        return true;
    }
};