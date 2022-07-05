class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map <int , int> hash;
        for(auto i: nums) hash[i]++;
        
        int ans = 0;
        for(auto i: nums) {
            if(hash[i - 1] == 0) {
                int start = 0;
                int count = 0;
                while(hash[i + start] != 0) {
                    count++;
                    start++;
                }
                ans = max(ans , count);
            }
        }
        return ans;
    }
};