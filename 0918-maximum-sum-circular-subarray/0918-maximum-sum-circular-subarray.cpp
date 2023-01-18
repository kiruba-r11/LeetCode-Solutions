class Solution {
public:
    int maxSubarraySum(vector <int> &nums) {
        int maxSum = nums[0] , curSum = nums[0];
        int n = nums.size();
        
        // Kadane's Algo to find max sum of the subarray
        for(int i = 1; i < n; i++) {
            curSum = max(nums[i] , curSum + nums[i]);
            maxSum = max(maxSum , curSum);
        }
        
        return maxSum;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        /*
        
        O(N) time and O(1) space complexity
        Idea -> Kadane's Algorithm
        
            There are two possibilities (The region under | | is the maximum sum of the subarray):
                1. ------  |------|  ------  
                2. |---|  ------  |-------| 
                
            In first case, the answer is just the maximum sum of the subarray.
            In second case, the answer is sum of the array - minimum sum of the subarray.
            
            Finally max of both will be the maximum sum of the subarray in circular array
        
        */
        
        int sum = 0 , n = nums.size();
        
        int maxSum = maxSubarraySum(nums);
        
        // Making the array values negative, so max sum of this modified array will be the min sum of the original array
        for(int i = 0; i < n; i++) {
            // Finding array sum before modifying it
            sum += nums[i];
            nums[i] *= -1;
        }
        
        int minSum = maxSubarraySum(nums);
        
        int maxCircularSubarraySum = max(maxSum , minSum + sum);
        
        if(sum == -1 * minSum) maxCircularSubarraySum = maxSum;
        
        return maxCircularSubarraySum;
    }
};