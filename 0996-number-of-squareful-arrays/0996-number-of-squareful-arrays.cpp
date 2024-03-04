class Solution {
public:
    bool perfect_square(long long num) {
        long long low = 0 , high = num;
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if(mid * mid == num) return true;
            if(mid * mid < num) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
    
    unordered_map <int , int> count;
    unordered_map <int , unordered_set <int>> store;
    int ans = 0;
    
    void dfs(int element , int left) {
        count[element]--;
        
        if(left == 0) ans++;
        for(auto i: store[element]) {
            if(count[i] != 0) dfs(i , left - 1);
        }
        
        count[element]++;
    }
    
    int numSquarefulPerms(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            count[nums[i]]++;
            for(int j = i + 1; j < n; j++) {
                long long pair = nums[i] + nums[j];
                if(perfect_square(pair)) {
                    store[nums[i]].insert(nums[j]);
                    store[nums[j]].insert(nums[i]);
                }
            }
        }
        
        for(auto i: count) dfs(i.first , n - 1);
        return ans;
    }
};