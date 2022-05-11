class Solution {
public:
    int solve(int n , int prev) {
        
        if(n == 0) return 1;
        
        int ans = 0;
        for(int i = prev; i <= 5; i++) {
            ans += solve(n - 1 , i);
        }
        
        return ans;
    }
    int countVowelStrings(int n) {
        return solve(n , 1);
    }
};