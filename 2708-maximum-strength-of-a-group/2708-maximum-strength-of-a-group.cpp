class Solution {
public:
    long long dfs(vector <int> &nums) {
        
        sort(nums.begin() , nums.end());
        
        int n = nums.size();
        int cntpos = 0;
        int cntneg = 0;
        
        long long pos = 1;
        long long neg = 1;
        
        for(int i = n - 1; i >= 0; i--) {
            if(nums[i] > 0) {
                cntpos++;
                pos = pos * nums[i];
            } else {
                break;
            }
        }
        
        int idx = -1;
        
        for(int i = 0; i < n; i++) {
            if(nums[i] < 0) {
                neg = neg * nums[i];
                cntneg++;
            } else {
                idx = i - 1;
                break;
            }
        }

        if(cntpos == 0 && cntneg == 0) return 0;
        else if(cntneg == 0) return pos;
        else if(cntpos == 0) {
            if(cntneg == 1) {
                if(n - (cntpos + cntneg) != 0) return 0;
                return nums[idx == -1 ? n - 1 : idx];
            } else {
                if(neg < 0) neg /= nums[idx == -1 ? n - 1 : idx];
                return neg;
            }
        } else {
            if(cntneg == 1) return pos;
            if(neg < 0) neg /= nums[idx == -1 ? n - 1 : idx];
            return pos * neg;
        }
        
        return 0;
    }
    
    long long maxStrength(vector<int>& nums) {
        return dfs(nums);
    }
};