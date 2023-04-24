class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int size = n + 1;
        
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) cnt++;
        }
        
        if(cnt == n) return 0;
        if(cnt != 0) return n - cnt;
            
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                int gcd = nums[i];
                for(int k = i; k <= j; k++) {
                    gcd = __gcd(gcd , nums[k]);
                }
                
                if(gcd == 1) {
                    size = min(size , j - i);
                }
            }
        }
        
        return size == n + 1 ? -1 : size + n - 1;
    }
};