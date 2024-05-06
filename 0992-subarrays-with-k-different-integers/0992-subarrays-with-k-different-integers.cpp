class Solution {
public:
    int solve(vector <int> &nums , int k) {
    
        int n = nums.size();
        int i = 0 , j = 0;
        map <int , int> hash;
        int ans = 0;
        
        while(j < n) {
            hash[nums[j]]++;
            while(i < j && hash.size() > k) {
                hash[nums[i]]--;
                if(hash[nums[i]] == 0) hash.erase(nums[i]);
                i++;
            }
            if(hash.size() <= k) ans += j - i + 1;
            j++;
        }
        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums , k) - solve(nums , k - 1);
    }
};