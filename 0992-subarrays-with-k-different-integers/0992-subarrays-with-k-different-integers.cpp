class Solution {
public:
    int slide(vector <int> nums , int k) {
        
        int i = 0 , j = 0;
        int n = nums.size();
        int ans = 0;
        map <int , int> hash;
        
        while(j < n) {
            hash[nums[j]]++;
            while(hash.size() > k) {
                if(hash[nums[i]] == 1) hash.erase(nums[i]);
                else hash[nums[i]]--;
                i++;
            }
            if(hash.size() <= k) ans += j - i + 1;
            j++;
        }
        
        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        return slide(nums , k) - slide(nums , k - 1);
    }
};