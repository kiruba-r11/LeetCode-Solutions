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
    
    set <vector <int>> s;
    int ans = 0;
    
    void solve(int n , map <int , int> &nums , unordered_map <int , unordered_map <int , bool>> &store , vector <int> &cur) {
        
        if(cur.size() == n) {
            ans++;
            return;
        }
        
        for(auto it: nums) {
            if(nums[it.first] != 0) {
                if(cur.size() == 0) {
                    cur.push_back(it.first);
                    nums[it.first]--;
                    solve(n , nums , store , cur);
                    nums[it.first]++;
                    cur.pop_back();
                } else {
                    if(store[cur.back()].find(it.first) != store[cur.back()].end()) {
                        cur.push_back(it.first);
                        nums[it.first]--;
                        solve(n , nums , store , cur);
                        nums[it.first]++;
                        cur.pop_back();
                    }
                }
            }
        }
    }
    
    int numSquarefulPerms(vector<int>& nums) {
        int n = nums.size();
        map <int , int> arr;
        unordered_map <int , unordered_map <int , bool>> store;
        sort(nums.begin() , nums.end());
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                long long pair = nums[i] + nums[j];
                if(perfect_square(pair)) {
                    store[nums[i]][nums[j]] = true;
                    store[nums[j]][nums[i]] = true;
                }
            }
        }
        
        for(int i = 0; i < n; i++) arr[nums[i]]++;
        
        for(int i = 0; i < n; i++) {
            if(store.find(nums[i]) == store.end()) return 0;
        }
        
        vector <int> cur;
        solve(n , arr , store , cur);
        return ans;
    }
};