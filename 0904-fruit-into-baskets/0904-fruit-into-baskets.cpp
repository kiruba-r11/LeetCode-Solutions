class Solution {
public:
    bool ispossible(vector <int> &nums , int k , int limit) {
    
        int i = 0 , j = 0;
        int n = nums.size();
        map <int , int> hash;
        
        while(j < n) {
            int window = j - i + 1;
            if(window <= k) {
                hash[nums[j]]++;
                if(window == k) {
                    if(hash.size() <= limit) return true;
                } 
                j++;
            } else {
                if(hash[nums[i]] == 1) hash.erase(nums[i]);
                else hash[nums[i]]--;
                i++;
            }
        }
        
        return false;
    }
    
    int totalFruit(vector<int>& fruits) {
        // Find the longest subarray such that the distinct elements are less than or equal to two
        int n = fruits.size();
        int low = 1 , high = n;
        int ans = 0;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            bool check = ispossible(fruits , mid , 2);
            if(check) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};