class Solution {
public:
    void reverseString(vector<char>& s) {
        
        /*
        
        O(N) time and O(1) space complexity
        
        */
        
        int start = 0 , end = s.size() - 1;
        while(start < end) {
            swap(s[start++] , s[end--]);
        }
        
    }
};