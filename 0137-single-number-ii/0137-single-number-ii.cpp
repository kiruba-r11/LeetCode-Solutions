class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        int pow = 1;
        for(int i = 0; i < 32; i++) {
            int cnt = 0;
            for(int j = 0; j < nums.size(); j++) {
                if(nums[j] & (1 << i))
                    cnt++;
            }
            if(cnt % 3 != 0)
                ans = ans | (1 << i);
            // ans+=cn*pow(2,i);
        }
        return ans;
    }
};