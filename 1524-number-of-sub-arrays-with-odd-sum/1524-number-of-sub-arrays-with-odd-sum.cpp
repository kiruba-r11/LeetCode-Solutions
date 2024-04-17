class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        int m = 1e9 + 7;
        long long ans = 0;
        map <int , int> hash;
        hash[sum] = 1;
        
        long long total = (n + 1) * 1LL * n / 2;
        
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            ans += hash[sum % 2];
            hash[sum % 2]++;
        }
        
        return (total - ans + m) % m;
    }
};