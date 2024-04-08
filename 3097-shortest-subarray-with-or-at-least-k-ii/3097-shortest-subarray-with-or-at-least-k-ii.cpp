class Solution {
public:
    void set(int num , vector <int> &bits) {
        for(int i = 0; i < 31; i++) {
            if(num & (1 << i)) {
                bits[i]++;
            }
        }
    }
    
    void unset(int num , vector <int> &bits) {
        for(int i = 0; i < 31; i++) {
            if(num & (1 << i)) {
                bits[i]--;
            }
        }
    }
    
    int findVal(vector <int> &bits) {
        int mask = 0;
        for(int i = 0; i < 31; i++) {
            if(bits[i] != 0) mask = mask | (1 << i);
        }
        return mask;
    }
    
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int i = 0 , j = 0;
        int n = nums.size();
        int val = 0;
        int ans = n + 1;
        
        vector <int> bits(31);
        
        if(k == 0) return 1;
        
        while(j < n) {
            set(nums[j] , bits);
            val = findVal(bits);

            while(val >= k) {
                unset(nums[i] , bits);
                int tempval = findVal(bits);
                
                if(tempval < k) {
                    set(nums[i] , bits);
                    break;
                }
                
                val = tempval;
                i++;
            }
            
            if(val >= k) ans = min(ans , j - i + 1);
            j++;
        }
        
        return ans == n + 1 ? -1 : ans;
    }
};