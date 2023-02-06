class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> a(2 * n);
        for(int i = 0 , j = 0; i < 2 * n; i += 2 , j++) {
            a[i] = nums[j];
            a[i + 1] = nums[n + j];
        }
        return a;
    }
};