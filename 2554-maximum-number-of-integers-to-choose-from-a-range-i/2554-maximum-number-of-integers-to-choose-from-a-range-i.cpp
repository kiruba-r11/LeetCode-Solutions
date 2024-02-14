class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_map <int , int> hash;
        for(auto i: banned) hash[i] = true;
        
        int sum = 0;
        int cnt = 0;
        for(int i = 1; i <= n; i++) {
            if(hash.find(i) == hash.end()) {
                if(sum + i > maxSum) break;
                sum += i;
                cnt++;
            }
        }
        
        return cnt;
    }
};