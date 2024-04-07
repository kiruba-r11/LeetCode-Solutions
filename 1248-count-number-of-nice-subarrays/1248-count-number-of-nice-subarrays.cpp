class Solution {
public:
    int slide(vector <int> &nums , int k) {
        int i = 0 , j = 0;
        int n = nums.size();
        int odd = 0;
        int ans = 0;
        
        while(j < n) {
            if(nums[j] & 1) odd++;
            while(odd > k) {
                if(nums[i] & 1) odd--;
                i++;
            }
            if(odd <= k) ans += j - i + 1;
            j++;
        }
        
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return slide(nums , k) - slide(nums , k - 1);
    }
};