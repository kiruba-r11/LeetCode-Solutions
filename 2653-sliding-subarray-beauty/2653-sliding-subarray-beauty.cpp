class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector <int> cnt(50);
        
        int i = 0 , j = 0;
        vector <int> ans;
        
        while(j < n) {
            int window = j - i + 1;
            if(window <= k) {
                if(nums[j] < 0) cnt[nums[j] + 50]++;
                
                if(window == k) {
                    int c = x;
                    for(int k = 0; k < 50; k++) {
                        bool check = false;
                        if(c <= cnt[k]) {
                            ans.push_back(k - 50);
                            check = true;  
                        } 
                        c -= cnt[k];
                        if(check) break; 
                    }
                    if(c > 0) ans.push_back(0);
                }
                
                j++;
            } else {
                if(nums[i] < 0) cnt[nums[i] + 50]--;
                i++;
            }
        }
        
        return ans;
    }
};