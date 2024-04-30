class Solution {
public:
    int helper(vector <int> &nums , int k) {
        int i = 0 , j = 0;
        int ans = 0;
        int n = nums.size();
        map <int , int> hash;
        
        while(j < n) {
            hash[nums[j]]++;
            while(hash.size() > k) {
                hash[nums[i]]--;
                if(hash[nums[i]] == 0) hash.erase(nums[i]);
                i++;
            }
            if(hash.size() <= k) ans += j - i + 1;
            j++;
        }
        return ans;
    }
    
    int countCompleteSubarrays(vector<int>& nums) {
        map <int , int> hash;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) hash[nums[i]]++;
        
        int k = hash.size();
        int ans = n * (n + 1) / 2 - helper(nums , k - 1);
        return ans;
    }
};