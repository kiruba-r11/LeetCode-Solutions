class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int n = nums.size();
        int i = 0 , j = 0 , ans = 0;
        unordered_map <int , int> hash;
        
        while(j < n) {
            if(hash.size() <= 2) {
                hash[nums[j]]++;
                if(hash.size() <= 2) ans = max(ans , j - i + 1);
                j++; 
            } else {
                while(hash.size() > 2) {
                    if(hash[nums[i]] == 1) hash.erase(nums[i]);
                    else hash[nums[i]]--;
                    i++;
                }
            }
        }
        
        return ans;
    }
};