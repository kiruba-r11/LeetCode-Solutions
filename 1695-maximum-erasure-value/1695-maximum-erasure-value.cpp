class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        /*
        
        O(N) time and space
        Idea -> Sliding Window (Variable Window Size -> Max. size of window is the answer) + Hash
        
        */
        
        int i = 0 , j = 0 , n = nums.size() , sum = 0 , maxsum = 0;
        unordered_map <int , int> hash;
        
        while(j < n) {
            
            // If the element is not found before, then its the unique one in the subarray
            while(j < n && hash[nums[j]] == 0) {
                sum += nums[j];
                hash[nums[j]]++;
                j++;
            }
            
            // The above loop stops if it reached out of bound or a dupliacte is found. So, by then we would have got our maxsum
            maxsum = max(sum , maxsum);
            
            // If the duplicate is found, make sure to remove elements from the left of the subarray until the required duplicate is removed
            while(i < j && j < n && hash[nums[j]] == 1) {
                sum -= nums[i];
                hash[nums[i]]--;
                i++;
            }
        }
        
        return maxsum;
    }
};