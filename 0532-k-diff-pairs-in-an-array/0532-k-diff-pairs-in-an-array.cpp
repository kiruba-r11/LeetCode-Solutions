class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        map <int , int> hash;
        
        if(k == 0) {
            for(int i = 0; i < n; i++) {
                hash[nums[i]]++;
            }
            for(auto i: hash) {
                if(i.second > 1) ans++;
            }
            return ans;
        }
        
        for(int i = 0; i < n; i++) {
            if(hash[nums[i]] != 0) continue;    
            ans += hash[nums[i] - k] + hash[nums[i] + k];
            hash[nums[i]]++;
        }
        
        return ans;
    }
};