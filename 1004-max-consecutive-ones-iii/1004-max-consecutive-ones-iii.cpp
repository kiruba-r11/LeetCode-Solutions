class Solution {
public:
    int longestOnes(vector<int>& nums, int flip) {
        int n = nums.size() , i = 0 , j = 0;
        int ans = 0;
        
        while(j < n) {
            if(nums[j] == 0) {
                if(flip > 0) {
                    flip--;
                    ans = max(ans , j - i + 1);
                    j++;
                } else {
                    while(flip == 0) {
                        if(nums[i] == 0) flip++;
                        i++;
                    }
                }
            } else {
                ans = max(ans , j - i + 1);
                j++;
            }
        }
        
        return ans;
    }
};