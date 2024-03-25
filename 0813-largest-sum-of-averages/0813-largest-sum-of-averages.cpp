class Solution {
public:
    double solve(vector <int> &nums , double i , double k , double cnt , double sum , map <vector <double> , double> &dp) {
        if(i == nums.size()) {
            return sum / cnt;
        }
    
        if(dp.find({i , k , cnt , sum}) != dp.end()) return dp[{i , k , cnt , sum}];
        
        double split = 0.0;
        double dontsplit = 0.0;
        
        dontsplit = solve(nums , i + 1 , k , cnt + 1 , sum + nums[i] , dp);
        
        if(k != 0) {
            split = (cnt ? (sum / cnt) : 0.0) + solve(nums , i + 1 , k - 1 , 1 , nums[i] , dp);
        }
     
        return dp[{i , k , cnt , sum}] = max(split , dontsplit);
    }
    
    double largestSumOfAverages(vector<int>& nums, int k) {
        map <vector <double> , double> dp;
        return solve(nums , 0 , k - 1 , 0 , 0.0 , dp);
    }
};