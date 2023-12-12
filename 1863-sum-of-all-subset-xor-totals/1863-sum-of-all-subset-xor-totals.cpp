class Solution {
public:
    int sum = 0;
    void solve(vector <int> &nums , int i , int &num) {
    
        if(i == nums.size()) {
            sum += num;
            return;
        }
        
        solve(nums , i + 1 , num);
        int temp = num ^ nums[i];
        solve(nums , i + 1 , temp);
        num = temp;
    }
    
    int subsetXORSum(vector<int>& nums) {
        int num = 0;
        solve(nums , 0 , num);
        return sum;
    }
};

/*

2
5
6
2 ^ 5
2 ^ 6
5 ^ 6
2 ^ 5 ^ 6

*/