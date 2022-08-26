class Solution {
public:
    bool solve(vector <int> &nums , vector <int> &cur) {
        
        if(cur.size() == nums.size()) {
            int num = 0;
            if(cur[0] != 0) {
                for(auto i: cur) {
                    num = num * 10 + i;
                }
                return (num & (num - 1)) == 0;
            }
            return false;
        }
        
        for(int index = 0; index < nums.size(); index++) {
            if(nums[index] != -1) {
                
                int temp = nums[index];
                nums[index] = -1;
                cur.push_back(temp);

                if(solve(nums , cur)) return true;
                
                cur.pop_back();
                nums[index] = temp;
            }
        }
        return false;
    }
    bool reorderedPowerOf2(int n) {
        
        vector <int> nums , cur;
        int temp = n;
        while(temp > 0) {
            int rem = temp % 10;
            nums.push_back(rem);
            temp /= 10;
        }
        reverse(nums.begin() , nums.end());
        
        return solve(nums , cur);
        
    }
};