class Solution {
public:
    int fpow(int b , int p) {
        
        int res = 1;
        while(p > 0) {
            if(p & 1) {
                res = res * b;
                p--;
            } else {
                b = b * b;
                p /= 2;
            }
        }
        
        return res;
    }
    int countPairs(vector<int>& nums) {
        map <int , int> hash;
        int n = nums.size() , mod = 1000000007;
        long long ans = 0;
        
        for(int i = 0; i < n; i++) {
            hash[nums[i]]++;
        }
        
        vector <int> pows;
        for(int i = 0; i <= 21; i++) {
            pows.push_back(fpow(2 , i));
        }
        
        for(auto i: hash) {
            int num = 0;
            // cout << "i : " << i.first << endl;
            for(auto j: pows) {
                // cout << j << " ";
                num = j - i.first;
                if(num >= 0 && hash.find(num) != hash.end()) {
                    // cout << i.first << " k " << j << endl;
                    if(num == i.first) {
                        ans += (i.second * 1L * (i.second - 1)) / 2;
                        ans %= mod;
                    } else {
                        ans += i.second * 1L * hash[num];
                        ans %= mod;
                    }
                }
            }
            hash.erase(i.first);
            // cout << endl;
        }
        
        return (int)ans;
    }
};