class Solution {
public:
    int step(vector <int> &bits , int num , bool set) {
        int val = 0;
        for(int i = 0; i < 31; i++) {
            if((1 << i) & num) {
                if(set) bits[i]++;
                else bits[i]--;
            }
            if(bits[i] != 0) val += (1 << i);
        }
        return val;
    }
    
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0 , j = 0;
        int ans = n + 1;
        int opr = 0;
        vector <int> bits(31 , 0);
        
        if(k == 0) return 1;
        
        while(j < n) {
            opr = step(bits , nums[j] , true);
            while(opr >= k) {
                int temp_opr = step(bits , nums[i] , false);
                if(temp_opr < k) {
                    step(bits , nums[i] , true);
                    break;
                }
                opr = temp_opr;
                i++;
            }
            if(opr >= k) ans = min(ans , j - i + 1);
            j++;
        }
        
        return ans == n + 1 ? -1 : ans;
    }
};