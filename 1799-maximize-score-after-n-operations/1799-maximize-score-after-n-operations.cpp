class Solution {
public:
    bool taken(int mask , int i) {
        if(mask & (1 << i)) return true;
        return false;
    }
    
    int usemask(int &mask , int i , int j) {
        int newmask = mask | (1 << i) | (1 << j);
        return newmask;
    }
    
    int solve(vector <int> &nums , int opr , int mask , vector <int> &dp) {
        int n = nums.size();
        int ans = 0;

        if(opr > n / 2) return 0;
        
        if(dp[mask] != -1) return dp[mask];
        
        for(int i = 0; i < n; i++) {
            if(taken(mask , i)) continue;
            for(int j = i + 1; j < n; j++) {
                if(taken(mask , j)) continue;
                int newmask = usemask(mask , i , j);
                int score = (opr + 1) * __gcd(nums[i] , nums[j]) + solve(nums , opr + 1 , newmask , dp);
                ans = max(ans , score);
            }
        }
        
        return dp[mask] = ans;
    }
    
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        int opr = 0;
        int mask = 0;
        vector <int> dp(16385 , -1);
        return solve(nums , opr , mask , dp);
    }
};