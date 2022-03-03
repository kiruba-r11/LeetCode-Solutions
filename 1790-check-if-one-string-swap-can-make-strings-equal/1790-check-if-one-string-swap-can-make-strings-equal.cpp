class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        
        /*
        
        O(N) time and O(1) space complexity
        Idea -> 
            
            1. We can either make 0 or 1 swaps
            2. To perform 0 swaps, both the string should already be same
            3. To perform 1 swap, one string should have 2 misplaced but equal characters
        
        */
        
        int n = s1.size();
        int misplaced = 0;
        int idx1 = -1 , idx2 = -1;
        
        for(int i = 0; i < n; i++) {
            if(s1[i] != s2[i]) {
                if(idx1 == -1) idx1 = i;
                else idx2 = i;
                misplaced++;
            }
            if(misplaced > 2) return false;
        }
        
        if(misplaced == 0) return true;
        if(misplaced == 1) return false;
        
        if(s1[idx1] == s2[idx2] && s1[idx2] == s2[idx1]) return true;
        return false;
    }
};