class Solution {
public:
    bool condition(vector <int> &bits) {
    
        for(int b = 0; b < 31; b++) {
            if(bits[b] > 1) return false;
        }
        
        return true;
    }
    
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0 , j = 0;
        int ans = 0;
        vector <int> bits(32);
        
        while(j < n) {
            for(int b = 0; b < 31; b++) {
                if(nums[j] & (1 << b)) bits[b]++;
            }
            
            while(condition(bits) == false) {
                for(int b = 0; b < 31; b++) {
                    if(nums[i] & (1 << b)) bits[b]--;
                }
                i++;
            }
            
            if(condition(bits) == true) ans = max(ans , j - i + 1);
            j++;
        }
        
        return ans;
    }
};