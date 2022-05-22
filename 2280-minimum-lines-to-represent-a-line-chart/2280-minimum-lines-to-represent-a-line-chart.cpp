class Solution {
public:
    int minimumLines(vector<vector<int>>& nums) {
        int n = nums.size();
        
        if(n <= 2) return n - 1;
        
        sort(nums.begin() , nums.end());
        int dx = nums[1][0] - nums[0][0];
        int dy = nums[1][1] - nums[0][1];
        int gcd = __gcd(dx , dy);
        
        dx /= gcd;
        dy /= gcd;
        
        int ans = 1;
        for(int i = 2; i < n; i++) {
            int ndx = nums[i][0] - nums[i - 1][0];
            int ndy = nums[i][1] - nums[i - 1][1];
            int ngcd = __gcd(ndx , ndy);
            
            ndx /= ngcd;
            ndy /= ngcd;
            
            if(!(dx == ndx && dy == ndy)) {
                ans++;
                dx = ndx;
                dy = ndy;
            }
        }
        
        return ans;
    }
};