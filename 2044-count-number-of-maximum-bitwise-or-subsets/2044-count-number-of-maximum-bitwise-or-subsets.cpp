class Solution {
public:
    void subsetOR(vector <int> &nums , int i , int &cur , int &max_or , int &cnt) {
        
        if(i == nums.size()) {
            if(cur > max_or) {
                max_or = cur;
                cnt = 1;
            } else if(cur == max_or) {
                cnt++;
            } 
            
            return;
        }
    
        // exclude element
        subsetOR(nums , i + 1 , cur , max_or , cnt);
        
        // make effort
        int temp = cur;
        cur = cur | nums[i];
        
        // include element
        subsetOR(nums , i + 1 , cur , max_or , cnt);
        
        // undo effort
        cur = temp;
        
    }
    
    int countMaxOrSubsets(vector<int>& nums) {
        int cur = 0 , cnt = 0 , max_or = 0;
        subsetOR(nums , 0 , cur , max_or , cnt);
        return cnt;
    }
};