class Solution {
public:
    int splitNum(int num) {
        vector <int> nums;
        while(num) {
            nums.push_back(num % 10);
            num /= 10;
        }
        
        sort(nums.begin() , nums.end());
        int num1 = 0 , num2 = 0;
        
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(i & 1) num2 = num2 * 10 + nums[i];
            else num1 = num1 * 10 + nums[i];
        }
        
        return num1 + num2;
    }
};