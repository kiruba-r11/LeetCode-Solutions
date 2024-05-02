class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0 , j = 0;  
        map <int , int> hash;
        long long ans = 0;
        long long pair = 0;
        
        while(j < n) {
            pair += hash[nums[j]];
            hash[nums[j]]++;
            while(pair >= k) {
                hash[nums[i]]--;
                pair -= hash[nums[i]];
                i++;
            }
            if(pair < k) ans += j - i + 1;
            j++;
        }
        
        return n * 1LL * (n + 1) / 2 - ans;
    }
};

