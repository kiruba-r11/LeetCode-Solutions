class Solution {
public:
    int predict(vector <int> &nums , int i , int j) {
        
        if(i > j) return 0;
        
        return max(nums[i] + min(predict(nums , i + 2 , j) , predict(nums , i + 1 , j - 1)) , 
        nums[j] + min(predict(nums , i + 1 , j - 1) , predict(nums , i , j - 2)));
    }
    
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int sum_a = predict(nums , 0 , n - 1);    
        int sum = 0;
        for(int i = 0; i < n; i++) sum += nums[i];
        
        int sum_b = sum - sum_a;
        return sum_a >= sum_b;
    }
};