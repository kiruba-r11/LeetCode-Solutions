class Solution {
public:
    bool isHillOrValley(vector <int> &nums , int i , int j) {

        if(i == 0 || j == nums.size()) return false;
        
        if(nums[i] < nums[j] && nums[i] < nums[i - 1]) return true;
        if(nums[i] > nums[j] && nums[i] > nums[i - 1]) return true;
        
        return false;
    }
    int countHillValley(vector<int>& nums) {
        
        /*
        
        O(N) time and O(1) space complexity
        Idea -> For every element, adjacent element is its closest element. Just check the adjacent elements
        
        */
        
        int n = nums.size() , count = 0;
        
        for(int i = 0; i < n; i++) {
            int j = i + 1;
            while(j < n && nums[i] == nums[j]) j++;
            count += isHillOrValley(nums , i , j);
            i = j - 1;
        }
        
        return count;
    }
};