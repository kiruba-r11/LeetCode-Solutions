// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        /*
        
        O(logN) time and O(1) space complexity
        Idea -> Binary Search
        
        */
        
        int low = 1 , high = n , ans = n;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            bool isBad = isBadVersion(mid);
            if(isBad) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};