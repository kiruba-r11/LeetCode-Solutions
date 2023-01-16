class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size() , i = 0 , j = 0 , cnt = 0;
        map <int , int> hash;
        
        long long ans = 0;
        while(j < n) {
            hash[nums[j]]++;
            cnt += hash[nums[j]] - 1;
            
            while(cnt >= k && i <= j) {
                ans += n - j;
                cnt -= hash[nums[i]] - 1;
                hash[nums[i]]--;
                i++;
            }
            j++;
        }
        
        return ans;
    }
};