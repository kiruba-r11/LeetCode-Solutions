class Solution {
public:
    bool condition(int a , int b , int c) {
    
        int ab = a + b;
        int bc = b + c;
        int ca = c + a;
        
        return ab > c && bc > a && ca > b;
    }
    
    int bs(vector <int> &nums , int low , int high , int a , int b) {
        int ans = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(condition(a , b , nums[mid])) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        
        int ans = 0;
        for(int i = 0; i < n - 2; i++) {
            for(int j = i + 1; j < n - 1; j++) {
                int idx = bs(nums , j + 1 , n - 1 , nums[i] , nums[j]);
                if(idx != -1) ans += idx - j;
            }
        }
        
        return ans;
    }
};