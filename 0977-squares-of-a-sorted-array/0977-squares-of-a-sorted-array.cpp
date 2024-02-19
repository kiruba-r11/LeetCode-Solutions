class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int neg = -1;
        int zero = -1;
        int pos = -1;
        for(int i = 0; i < n; i++) {
            if(nums[i] < 0) neg = i;
            else if(nums[i] > 0) {
                if(pos == -1) pos = i;
            }
            else {
                if(zero == -1) zero = i;
            }
        }
        
        vector <int> ans(n);
        int ptr = 0;
        if(zero != -1) {
            while(zero < n && nums[zero] == 0) {
                ans[ptr] = 0;
                ptr++;
                zero++;
            }
        }
        if(neg != -1) {
            if(pos != -1) {
                
                while(neg >= 0 && pos < n) {
                    if(abs(nums[neg]) <= nums[pos]) {
                        ans[ptr] = nums[neg] * nums[neg];
                        neg--;
                        ptr++;
                    } else {
                        ans[ptr] = nums[pos] * nums[pos];
                        pos++;
                        ptr++;
                    }
                }
                
                while(neg >= 0) {
                    ans[ptr] = nums[neg] * nums[neg];
                    neg--;
                    ptr++;
                }
                
                while(pos < n) {
                    ans[ptr] = nums[pos] * nums[pos];
                    pos++;
                    ptr++;
                }
                
            } else {
                while(neg >= 0) {
                    ans[ptr] = nums[neg] * nums[neg];
                    neg--;
                    ptr++;
                }
            }
        } else {
            if(pos != -1) {
                while(pos < n) {
                    ans[ptr] = nums[pos] * nums[pos];
                    pos++;
                    ptr++;
                }
            }
        }
        
        return ans;
    }
};