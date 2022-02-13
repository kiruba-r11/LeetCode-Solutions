class Solution {
public:
    long long minimumRemoval(vector<int>& nums) {
        /*
            
        O(NlogN) time and O(N) (or O(1) based on prefix - suffix implementation) space complexity
        Idea -> Prefix + Suffix
        
        Eg:
        
        [1 , 3 , 5 , 9 , 10]
        
        [1 , 1 , 1 , 1 , 1] -> 
            (1 - 0) + (3 - 2) + (5 - 4) + (9 - 8) + (10 - 9) = 0 + 2 + 4 + 8 + 9 = 23
            
        [0 , 3 , 3 , 3 , 3] ->
            (1 - 1) + (3 - 0) + (5 - 2) + (9 - 6) + (10 - 7) = 1 + 0 + 2 + 6 + 7 = 16
            
        [0 , 0 , 5 , 5 , 5] ->
            (1 - 1) + (3 - 3) + (5 - 0) + (9 - 4) + (10 - 5) = 1 + 3 + 0 + 4 + 5 = 13
            
        [0 , 0 , 0 , 9 , 9] ->
            (1 - 1) + (3 - 3) + (5 - 5) + (9 - 0) + (10 - 1) = 1 + 3 + 5 + 0 + 1 = 10
            
        [0 , 0 , 0 , 0 , 10] ->
            (1 - 1) + (3 - 3) + (5 - 5) + (9 - 9) + (10 - 0) = 1 + 3 + 5 + 9 + 0 = 18
            
        */
        
        int n = nums.size();
        vector <long long> prefix(n , 0) , suffix(n , 0);
        long long ans = LLONG_MAX;
        
        sort(nums.begin() , nums.end());
        
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++) prefix[i] = prefix[i - 1] + nums[i];
        
        suffix[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--) suffix[i] = suffix[i + 1] + nums[i];

        for(int i = 0; i < n; i++) {
            long long temp = 0;
            int j = i + 1;
            while(j < n && nums[i] == nums[j]) j++;
            
            if(i == 0 && j >= n) temp = 0;
            else if(i == 0) temp = suffix[j] - (nums[i] * 1L * (n - j));
            else if(j >= n) temp = prefix[i - 1];
            else temp = prefix[i - 1] + suffix[j] - (nums[i] * 1L * (n - j));
            
            ans = min(ans , temp);
            i = j - 1;
        }
            
        return ans;
    }
};