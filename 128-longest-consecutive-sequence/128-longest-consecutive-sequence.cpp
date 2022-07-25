class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map <int , int> hash;
        for(auto i: nums) hash[i]++;
        
        int ans = 0;
        for(auto i: nums) {
            if(hash[i - 1] == 0) {
                int start = i;
                int cnt = 0;
                
                while(hash[start] != 0) {
                    start++;
                    cnt++;
                }
                
                ans = max(ans , cnt);
            }
        }
        
        return ans;
    }
};