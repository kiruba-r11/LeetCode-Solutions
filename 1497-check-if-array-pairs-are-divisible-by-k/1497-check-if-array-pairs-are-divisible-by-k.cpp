class Solution {
public:
    bool canArrange(vector<int>& nums, int k) {
        
        int n = nums.size();
        map <int , int> hash;
        for(int i = 0; i < n; i++) {
            int rem = (nums[i] % k + k) % k;
            hash[rem]++;
        }
        
        for(auto i: hash) {
            if(i.first == 0) continue;
            if(i.first * 2 == k) {
                if(hash[i.first] & 1) return false;
            } else  {
                int cnt = hash[i.first];
                int c_cnt = hash[k - i.first];
                if(cnt != c_cnt) return false;
            }
        }
        
        return true;
    }
};