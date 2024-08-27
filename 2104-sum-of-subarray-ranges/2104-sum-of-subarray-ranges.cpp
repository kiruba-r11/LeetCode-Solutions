class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector <int> nsr(n , n) , nsl(n , -1) , ngr(n , n) , ngl(n , -1);
        stack <int> s1 , s2 , s3 , s4;
        
        for(int i = 0; i < n; i++) {
            while(!s1.empty() && nums[s1.top()] > nums[i]) {
                s1.pop();
            }
            if(!s1.empty()) nsl[i] = s1.top();
            s1.push(i);
        }
        
        for(int i = 0; i < n; i++) {
            while(!s2.empty() && nums[s2.top()] < nums[i]) {
                s2.pop();
            }
            if(!s2.empty()) ngl[i] = s2.top();
            s2.push(i);
        }
        
        for(int i = n - 1; i >= 0; i--) {
            while(!s3.empty() && nums[s3.top()] >= nums[i]) {
                s3.pop();
            }
            if(!s3.empty()) nsr[i] = s3.top();
            s3.push(i);
        }
        
        for(int i = n - 1; i >= 0; i--) {
            while(!s4.empty() && nums[s4.top()] <= nums[i]) {
                s4.pop();
            }
            if(!s4.empty()) ngr[i] = s4.top();
            s4.push(i);
        }
        
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            long long si = i - nsl[i];
            long long sj = nsr[i] - i;
            
            long long gi = i - ngl[i];
            long long gj = ngr[i] - i;
            
            long long g = gi * gj * nums[i];
            long long s = si * sj * nums[i];
            
            ans += g - s;
        }
        
        return ans;
    }
};
