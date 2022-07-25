class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map <int , bool> hash1;
        unordered_map <int , int> hash2;
        for(auto i: nums) hash1[i] = true , hash2[i] = 1;
        
        int ans = 0;
        
        for(auto i: nums) {
            int j = i + 1;
            int cnt = 1;
            while(hash1[j] == true && hash2[j] == 1) {
                cnt++;
                j++;
            }
            hash2[i] = hash2[j] + cnt;
            ans = max(ans , hash2[i]);
        }
        
        return ans;
    }
};