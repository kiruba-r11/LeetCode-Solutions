class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_map <int , int> hash;
        hash[0] = 1;
        
        int prefix = 0 , cnt = 0;
        for(int i = 0; i < n; i++) {
            prefix += nums[i];
            
            if(hash[prefix - k] != 0) cnt += hash[prefix - k];
                
            hash[prefix]++;
        }
        
        return cnt;
        
    }
};


// [1,2,3,4,5,6,7,8,9]
// ------x-
// ---------x+k--


// [1,1,1]     h[1] = 1

// [1,-1,0]  [0->1 , ] cnt = 1(-1,1)



