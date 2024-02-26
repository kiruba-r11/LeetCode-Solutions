class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n = beans.size();
        int cnt = 1;
        
        long long sum = 0;
        long long prefix = 0;
        long long ans = LLONG_MAX;
        
        sort(beans.begin() , beans.end());
        
        for(int i = 0; i < n; i++) sum += beans[i];
        
        for(int i = 0; i < n; i++) {
            ans = min(ans , sum - beans[i] * 1LL * (n - i));
            prefix += beans[i];
        }
        
        return ans;
    }
};