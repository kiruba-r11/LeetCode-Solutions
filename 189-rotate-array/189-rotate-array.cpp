class Solution {
public:
    void reverse(vector <int> &nums , int start , int end) {
        
        // Reverse the array
        while(start < end) {
            swap(nums[start] , nums[end]);
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        
        // If k is greater than n, then the effective rotations is k % n
        k %= n;
        
        // Reverse the first n - k elements
        reverse(nums ,0 , n - 1 - k);
        
        // Reverse the last k elements
        reverse(nums ,n - k , n - 1);
        
        // Reverse the whole array
        reverse(nums ,0 , n - 1);
    }
};
