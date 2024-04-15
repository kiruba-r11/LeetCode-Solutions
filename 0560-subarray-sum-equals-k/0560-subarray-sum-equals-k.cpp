class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        /*
        
        O(N) time and space complexity
        Idea -> Hashing 
        
        Let the array be [i0 , i1 , i2 , i3 , .... i(n-1)]
        Here, if sum of elements from i0 to ia is X
        Also, if sum of elements from i0 to ib is X+K
        
        Then, the sum of elements from i(a+1) to ib is K.
        So, we just need to calculate prefix sum and store it in hash, and if the above condition satisfies, then increment the count
        
        */
        
        int n = nums.size();
        int prefix_sum = 0;
        int ans = 0;
        
        map <int , int> hash;
        hash[prefix_sum] = 1;
        
        for(int i = 0; i < n; i++) {
            prefix_sum += nums[i];
            if(hash.find(prefix_sum - k) != hash.end()) ans += hash[prefix_sum - k];
            hash[prefix_sum]++;
        }
       
        return ans;        
    }
};




