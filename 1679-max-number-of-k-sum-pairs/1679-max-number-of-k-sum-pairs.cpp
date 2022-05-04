class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map <int , int> hash;
        sort(nums.begin() , nums.end());
        for(auto i: nums) {
            hash[i]++;
        }
        
        int ans = 0;
        for(auto i: hash) {
            if(i.second != 0 && hash.find(k - i.first) != hash.end() && hash[k - i.first] != 0) {
                if(i.first == k - i.first) {
                    ans += i.second / 2;
                } else {
                    ans += min(i.second , hash[k - i.first]);
                }
                
                hash[i.first] = 0;
                hash[k - i.first] = 0;
            }
        }
        
        return ans;
        
    }
};