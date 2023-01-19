class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map <int , int> hash;
        hash[0] = 1;
        int sum = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int rem = (sum % k + k) % k;
            if(hash[rem] != 0) {
                count += hash[rem];
            }
            hash[rem]++;
        }
        return count;
    }
};